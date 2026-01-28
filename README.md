# Cmake + GTest + Clang + CI 学习仓库

这是我的第二个 C++ 工程化学习仓库，目标是掌握“仓库初始化”的核心流程：
构建、测试、代码格式化、静态分析和 CI。

## 包含内容
- CMake 构建工程
- GoogleTest 单元测试
- clang-format 代码格式化
- clang-tidy 静态分析
- GitHub Actions CI 自动化

## 项目功能
- `lowercase`：`to_lower`
- `main`

## 目录结构
```
.
├── include
├── src
├── tests
├── scripts
├── .github/workflows
├── CMakeLists.txt
├── .clang-format
├── .clang-tidy
└── README.md
```

## 环境要求
- CMake
- GCC/MinGW-w64
- GDB
- clang-format
- clang-tidy
- Git

> Windows + MSYS2 推荐安装：
> - `mingw-w64-x86_64-clang`
> - `mingw-w64-x86_64-clang-tools-extra`

## 构建与测试（Git Bash / MSYS2 MINGW64）
```bash
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
cmake --build build
ctest --test-dir build --output-on-failure
```

## clang-format
```bash
# 自动格式化
bash scripts/format.sh

# 只检查（CI 同款）
bash scripts/format_check.sh
```

## clang-tidy
```bash
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DENABLE_CLANG_TIDY=ON
cmake --build build
```

或单文件检查：
```bash
clang-tidy -p build src/lowercase.cpp
```

## CI（GitHub Actions）
CI 配置在 `.github/workflows/ci.yml`，push/PR 时自动：
- 构建
- 测试
- 格式检查

## 备注
本仓库以学习为目的，强调流程理解而非复杂功能。
# learn-cmake-gtest-clang-CI
