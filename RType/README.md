# R-Type

This project aims to recreate the [R-Type](https://fr.wikipedia.org/wiki/R-Type) game and add a multiplayer mode to it. we had to implement a multi-threaded server using [Boost::asio](https://www.boost.org/doc/libs/1_66_0/doc/html/boost_asio.html) and a graphical client in [SFML](https://www.sfml-dev.org/).

This project was not completed but my part is working. I had to make the tools that the devs were to use to make the game: 
  - GameObject class
  - Some Server and Client ECS
  - SharedLib class
  - Network class

## building instructions

- `./build_linux.sh` or `build_macos.sh`
