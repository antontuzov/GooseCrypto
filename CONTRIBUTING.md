# Contributing to GooseCrypto

Welcome! We're excited that you're interested in contributing to GooseCrypto. This document outlines the process for contributing to the project.

## Code of Conduct

By participating in this project, you are expected to uphold our Code of Conduct. Please report unacceptable behavior to the project maintainers.

## Getting Started

1. Fork the repository
2. Clone your fork: `git clone https://github.com/yourusername/goosecrypto.git`
3. Create a new branch: `git checkout -b feature/your-feature-name`
4. Make your changes
5. Test your changes
6. Commit your changes: `git commit -m "Add your commit message"`
7. Push to your fork: `git push origin feature/your-feature-name`
8. Create a pull request

## Development Setup

### Prerequisites

- C++17 compiler (GCC/Clang)
- CMake 3.10+
- OpenSSL development libraries
- Node.js 12+ (for JavaScript API)
- Google Test (for C++ tests)

### Building

```bash
# Build C++ components
make

# Build JavaScript components
cd api/javascript
npm install
npm run build
```

## Code Style

### C++

- Follow the Google C++ Style Guide
- Use 4 spaces for indentation
- Use meaningful variable and function names
- Comment your code where necessary
- Keep functions small and focused

### JavaScript/TypeScript

- Follow the Airbnb JavaScript Style Guide
- Use TypeScript for type safety
- Use 2 spaces for indentation
- Use camelCase for variables and functions
- Use PascalCase for classes and interfaces

## Testing

### C++ Tests

```bash
# Run all C++ tests
make test

# Run specific test
./build/block_test
```

### JavaScript Tests

```bash
# Run JavaScript tests
cd api/javascript
npm test
```

## Pull Request Process

1. Ensure any install or build dependencies are removed before the end of the layer when doing a build
2. Update the README.md with details of changes to the interface, this includes new environment variables, exposed ports, useful file locations and container parameters
3. Increase the version numbers in any examples files and the README.md to the new version that this Pull Request would represent
4. Your pull request will be reviewed by maintainers, who may request changes
5. Once approved, your pull request will be merged

## Reporting Issues

Before reporting an issue, please check the existing issues to avoid duplicates. When reporting a new issue, include:

1. A clear and descriptive title
2. A detailed description of the problem
3. Steps to reproduce the issue
4. Expected behavior
5. Actual behavior
6. Environment information (OS, compiler version, etc.)

## Feature Requests

We welcome feature requests! Please create an issue with:

1. A clear and descriptive title
2. A detailed explanation of the proposed feature
3. The problem this feature would solve
4. How the feature would be used

## Code Review Process

All submissions require review. We use GitHub pull requests for this process. Consult [GitHub Help](https://help.github.com/articles/about-pull-requests/) for more information on using pull requests.

## Community

- Join our discussions on GitHub Issues
- Follow us on Twitter [@GooseCrypto](https://twitter.com/GooseCrypto) for updates

Thank you for contributing to GooseCrypto!