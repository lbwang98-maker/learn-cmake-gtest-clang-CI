#!/usr/bin/env bash
set -euo pipefail

files=(
  "include/lowercase.h"
  "src/lowercase.cpp"
  "src/main.cpp"
  "tests/test.cpp"
)

clang-format --dry-run -Werror "${files[@]}"
