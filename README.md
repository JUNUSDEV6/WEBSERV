# WebServ - HTTP Server Implementation in C++98

[![42](https://img.shields.io/badge/42-Project-blue)](https://42.fr)
[![C++98](https://img.shields.io/badge/C++98-Standard-green)](https://en.cppreference.com/w/cpp/98)
[![Status](https://img.shields.io/badge/Status-Completed-success)](https://github.com/yohanafi/webserv)

## 📋 Table of Contents
- [About](#about)
- [Features](#features)
- [Architecture](#architecture)
- [Installation](#installation)
- [Usage](#usage)
- [Configuration](#configuration)
- [Testing](#testing)
- [Project Structure](#project-structure)
- [Contributing](#contributing)

## 🎯 About

**WebServ** is a high-performance HTTP/1.1 web server implementation written in C++98. This project is inspired by NGINX and implements core web server functionality including static file serving, CGI script execution, and multiple server configurations.

The server is built from scratch using only C++98 standard library and system calls, demonstrating low-level network programming, HTTP protocol implementation, and server architecture design.

## ✨ Features

### Core HTTP Features
- **HTTP/1.1 Protocol Support** - Complete HTTP/1.1 implementation
- **Multiple HTTP Methods** - GET, POST, DELETE support
- **Static File Serving** - Efficient static content delivery
- **CGI Support** - Execute Python and other CGI scripts
- **File Upload** - Multipart form data handling
- **Directory Listing** - Auto-index functionality

### Server Architecture
- **Non-blocking I/O** - Using epoll for high performance
- **Multiple Server Instances** - Support for multiple virtual hosts
- **Custom Configuration** - NGINX-inspired configuration syntax
- **Error Page Handling** - Custom error pages for different HTTP status codes
- **Request Routing** - Location-based request routing

### Advanced Features
- **Concurrent Connections** - Handle multiple clients simultaneously
- **Request Timeouts** - Configurable timeout handling
- **File Upload Limits** - Configurable maximum body size
- **Security Features** - Path traversal protection
- **Logging System** - Comprehensive error and access logging

## 🏗️ Architecture

### Components Overview

```
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│   ServerHandler │────│   ServerExec    │────│     Client      │
│                 │    │                 │    │                 │
│  - Config mgmt  │    │  - Socket mgmt  │    │  - HTTP parsing │
│  - Server init  │    │  - Epoll events │    │  - Response gen │
│  - Cleanup      │    │  - Client mgmt  │    │  - CGI handling │
└─────────────────┘    └─────────────────┘    └─────────────────┘
```

### Key Classes
- **`ServerHandler`** - Main server orchestrator and signal handling
- **`ServerExec`** - Individual server instance with epoll management
- **`Client`** - HTTP client connection and request processing
- **`Config`** - Configuration file parsing and management
- **`Socket`** - Low-level socket operations and networking
- **`HttpForm`** - HTTP message parsing and generation
- **`Interface`** - CGI script execution and communication

## 🚀 Installation

### Prerequisites
- **Compiler**: g++ with C++98 support
- **Operating System**: Linux (tested on Ubuntu/Debian)
- **Dependencies**: Standard C++ library only

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/yohanafi/webserv.git
cd webserv

# Compile the project
make

# Clean build files (optional)
make clean
```

### Build Targets
- `make` - Build the webserv executable
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Rebuild everything

## 💻 Usage

### Basic Usage

```bash
# Start server with default configuration
./webserv

# Start server with custom configuration
./webserv configuration/custom.conf

# Available configuration files:
./webserv configuration/server.conf           # Basic setup
./webserv configuration/multiple_servers.conf # Multiple virtual hosts
./webserv configuration/redirect_server.conf  # With redirections
```

### Testing the Server

```bash
# Test basic functionality
curl http://localhost:8080/

# Test file upload
curl -X POST -F "file=@example.txt" http://localhost:8080/upload/

# Test CGI scripts
curl "http://localhost:8080/cgi/calculator.py?operations=2+2"

# Test directory listing
curl http://localhost:8080/images/
```

## ⚙️ Configuration

The server uses NGINX-inspired configuration syntax:

```nginx
server {
    server_name example_server;
    listen 8080;
    host 127.0.0.1;
    client_max_body_size 1;  # Max body size in MB
    
    # Root location
    location / {
        root www/;
        method GET;
    }
    
    # File upload location
    location /upload/ {
        root www/upload/;
        client_body_temp_path www/images/clientUploadFiles;
        method GET;
        method POST;
        method DELETE;
        auto-index on;
    }
    
    # CGI scripts location
    location /cgi/ {
        root www/script/;
        method GET;
        method POST;
    }
    
    # Error pages
    error_page 404 www/html/404.html;
    error_page 500 www/html/500.html;
}
```

### Configuration Options

| Directive | Description | Example |
|-----------|-------------|---------|
| `server_name` | Server identifier | `server_name my_server;` |
| `listen` | Port to listen on | `listen 8080;` |
| `host` | IP address to bind | `host 127.0.0.1;` |
| `client_max_body_size` | Max request body size (MB) | `client_max_body_size 10;` |
| `location` | Route configuration | `location /api/ { ... }` |
| `root` | Document root directory | `root www/html/;` |
| `method` | Allowed HTTP methods | `method GET; method POST;` |
| `auto-index` | Directory listing | `auto-index on;` |
| `error_page` | Custom error pages | `error_page 404 /404.html;` |

## 🧪 Testing

### Stress Testing with Siege

```bash
# Install siege (if not already installed)
sudo apt-get install siege

# Basic load test
siege -c 10 -r 100 http://localhost:8080/

# File upload test
siege -c 5 -r 50 -H "Content-Type: multipart/form-data" \
  --method=POST http://localhost:8080/upload/
```

### Manual Testing

1. **Static Files**: Place files in `www/` directory and access via browser
2. **File Upload**: Use the upload form at `http://localhost:8080/html/post.html`
3. **CGI Scripts**: Test calculator at `http://localhost:8080/html/cgi.html`
4. **Error Pages**: Access non-existent pages to test error handling

## 📁 Project Structure

```
webserv/
├── Makefile                    # Build configuration
├── README.md                   # Project documentation
├── configuration/              # Server configuration files
│   ├── server.conf            # Basic server config
│   ├── multiple_servers.conf  # Multi-server config
│   └── redirect_server.conf   # Redirect examples
├── inc/                       # Header files
│   ├── define.h              # Constants and definitions
│   └── Libraries.h           # System includes
├── srcs/                      # Source code
│   ├── main.cpp              # Application entry point
│   ├── ServerHandler.*       # Main server management
│   ├── EPOLL/               # Socket and epoll handling
│   │   ├── ServerExec.*     # Server execution logic
│   │   └── Socket.*         # Socket operations
│   ├── HTTP/                # HTTP protocol implementation
│   │   ├── Client.*         # Client connection handling
│   │   ├── HttpForm.*       # HTTP message base class
│   │   ├── HttpFormIn.*     # HTTP request parsing
│   │   ├── HttpFormOut.*    # HTTP response generation
│   │   └── Client*.cpp      # Method-specific handlers
│   ├── NGINX/               # Configuration management
│   │   ├── Config.*         # Configuration parser
│   │   ├── Location.*       # Location block handling
│   │   ├── Parsing.*        # Configuration file parsing
│   │   └── ServerSettings.* # Server configuration
│   ├── CGI/                 # CGI script interface
│   │   └── Interface.*      # CGI execution logic
│   └── utils/               # Utility functions
│       └── Utils.*          # Helper functions
└── www/                       # Web content directory
    ├── index.html            # Default homepage
    ├── html/                 # Static HTML pages
    ├── images/               # Image assets
    ├── script/               # CGI scripts
    ├── upload/               # Upload directory
    └── log/                  # Server logs
```

## 🤝 Contributing

This project was developed as part of the 42 school curriculum. While it's primarily for educational purposes, contributions and improvements are welcome!

### Development Guidelines
- Follow C++98 standard strictly
- Maintain NGINX-compatible configuration syntax
- Add comprehensive error handling
- Write clean, documented code
- Test thoroughly with various HTTP clients

### Team Members
- **yohanafi** 
- **iait-ouf** 
- **kdegryse** 

## 📚 Resources

- [HTTP/1.1 RFC 2616](https://tools.ietf.org/html/rfc2616)
- [NGINX Configuration Guide](https://nginx.org/en/docs/)
- [CGI Specification RFC 3875](https://tools.ietf.org/html/rfc3875)
- [epoll Manual](https://man7.org/linux/man-pages/man7/epoll.7.html)

## 📄 License

This project is part of the 42 school curriculum and is intended for educational purposes.

---

**Note**: This server is built for educational purposes and may not be suitable for production use without additional security hardening and optimization.
