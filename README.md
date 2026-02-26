# 🔐 Password Strength Checker (C++)

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![PRs](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)

A robust, professional-grade password strength checker written in C++ that evaluates password security based on multiple criteria. This program demonstrates clean code practices, object-oriented design, and comprehensive validation logic.

## ✨ Features

- ✅ **Multi-criteria Analysis**
  - Password length evaluation
  - Uppercase letter detection
  - Lowercase letter detection  
  - Number detection
  - Special character detection

- 📊 **Intelligent Scoring System**
  - 8-point comprehensive scale
  - Bonus points for character combination
  - 5 strength levels (Very Weak to Very Strong)

- 💡 **User-Friendly Interface**
  - Visual feedback with checkmarks (✓/✗)
  - Actionable improvement suggestions
  - Password examples for reference
  - Multiple password checking capability

## 🚀 How It Works

The program analyzes passwords using the following criteria:

| Criteria | Points | Description |
|----------|--------|-------------|
| Length ≥ 12 | 3 | Maximum length points |
| Length ≥ 8 | 2 | Medium length |
| Length ≥ 6 | 1 | Minimum acceptable |
| Uppercase | 1 | Contains A-Z |
| Lowercase | 1 | Contains a-z |
| Numbers | 1 | Contains 0-9 |
| Special Chars | 1 | Contains !@#$% etc. |
| Bonus | 1 | All types + length ≥ 8 |

## 📋 Prerequisites

- C++17 compatible compiler
- Standard C++ libraries

## 🔧 Installation & Usage

1. **Clone the repository**
```bash
git clone https://github.com/mckennamakran/password-strength-checker-cpp.git
cd password-strength-checker-cpp
