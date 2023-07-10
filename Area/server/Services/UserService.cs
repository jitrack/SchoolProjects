using System.Reflection;
using Area.Database;
using Area.Models;
using Area.Services.OAuthService;
using Area.Utils;
using MongoDB.Bson;
using MongoDB.Driver;

namespace Area.Services;

public class UserService
{
    private readonly IMongoCollection<User> _users;
    private readonly HttpContextAccessor _httpContextAccessor;
    private User? _user = null;
    
    public UserService(DatabaseContext databaseContext, HttpContextAccessor httpContextAccessor)
    {
        _users = databaseContext.Database.GetCollection<User>("Users");
        _httpContextAccessor = httpContextAccessor;
    }

    public User? GetCurrentUser(bool refresh = false)
    {
        if (_user == null || refresh) {
            string? id = _httpContextAccessor.GetUserIdFromJwt();
            if (id != null) {
                User ?user = GetUserById(id);
                _user = user;
            }
        }
        return _user;
    }
    
    public List<User> GetUsers() => _users.Find(_ => true).ToList();

    public User GetUserById(string id)
    {
        return _users.Find<User>(user => user.Id == id).FirstOrDefault();
    }

    public User? Create(User user)
    {
        if (_users.Find(u => u.Email == user.Email).FirstOrDefault() != null)
            return null;
        _users.InsertOne(user);
        return user;
    }

    public User? FindUserFromEmail(string email)
    {
        return _users.Find(x => x.Email == email).FirstOrDefault();
    }

    public void SetGithubOAuthData(string username)
    {
        User user = GetCurrentUser();
        var objectId = ObjectId.Parse(user.Id);
        var filter = Builders<User>.Filter.Eq(nameof(User.Id), user.Id);
        var update = Builders<User>.Update.Set(e => e.GithubOAuth.username, username);
        _users.UpdateOne(filter, update);
    }

    public void SetDailymotionOAuthData(string id)
    {
        User user = GetCurrentUser();
        var objectId = ObjectId.Parse(user.Id);
        var filter = Builders<User>.Filter.Eq(nameof(User.Id), user.Id);
        var update = Builders<User>.Update.Set(e => e.DailymotionOAuth.id, id);
        _users.UpdateOne(filter, update);
    }

    public void AddOAuth(string userId, OAuthEnum service, string accessToken)
    {
        User? user = GetUserById(userId);
        string serviceName = Enum.GetName(service);
        _users.UpdateOne(e => e.Id == userId, Builders<User>.Update.Set(serviceName, new OAuth() {
            accessToken = accessToken
        }));
    }
    
    public void RemoveOAuth(string userId, OAuthEnum service)
    {
        User? user = GetUserById(userId);
        string serviceName = Enum.GetName(service);
        PropertyInfo oauth = user.GetType().GetProperty(serviceName);
        Debug.WriteJson(user);
        oauth.SetValue(user, null, null);
        Debug.WriteJson(user);
        _users.ReplaceOne(e => e.Id == userId, user);
    }
}