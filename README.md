# 🐍 Classic Snake Game

> A classic Snake game implemented in **C** using a **Singly Linked List** and **raylib**.

![Language](https://img.shields.io/badge/Language-C-blue)
![Graphics](https://img.shields.io/badge/Graphics-raylib-green)
![Data Structure](https://img.shields.io/badge/Data%20Structure-Linked%20List-orange)
![Status](https://img.shields.io/badge/Status-In%20Development-yellow)

---

## 📌 Project Overview

Classic Snake Game is a **Data Structures mini-project** that recreates the classic Snake game while demonstrating the practical use of a **Singly Linked List**.

Each segment of the snake is represented by a linked-list node. The project combines:

- C programming
- Singly Linked Lists
- Dynamic memory allocation
- Game logic
- Collision detection
- Graphical programming with raylib
- Git & GitHub collaboration

---

## 🎯 Problem Statement

The snake's length changes continuously during gameplay. A data structure that can dynamically add and remove elements is therefore suitable for representing the snake.

**Problem:**  
Design and implement an interactive Snake game in which the snake's body is managed dynamically using a **Linked List**, while providing a graphical interface and standard Snake mechanics.

---

## 💡 Proposed Solution

The game will be implemented in **C using raylib**, with the snake represented as a **Singly Linked List**.

Each node represents one snake segment:

```text
HEAD
 ↓
┌───────┐    ┌───────┐    ┌───────┐
│ x, y  │ -> │ x, y  │ -> │ x, y  │ -> NULL
└───────┘    └───────┘    └───────┘
```

When food is eaten, a new node is added to the snake. During normal movement, the tail is removed while a new head position is created.

This demonstrates:

- Nodes
- Pointers
- Dynamic memory allocation
- Linked-list traversal
- Insertion
- Deletion

---

## 🎮 Game Features

### Core Features

- **Snake Movement** — `WASD` / Arrow Keys
- **Food** — Random valid food generation
- **Snake Growth** — New linked-list node when food is eaten
- **Score** — Increases when food is consumed
- **Wall Collision** — Game ends when the snake hits the boundary
- **Self Collision** — Game ends when the snake hits its own body
- **Start Screen** — Instructions and game start
- **Game Over** — Final score and restart/exit options
- **Restart** — Resets the snake, score, food and game state

---

## 🧠 Data Structure Used

### Singly Linked List

The primary data structure is a **Singly Linked List**.

Each snake segment is represented by a node:

```c
struct Node {
    int x;
    int y;
    struct Node *next;
};
```

Example:

```text
Before eating:

HEAD → [1] → [2] → [3] → NULL

After eating:

HEAD → [1] → [2] → [3] → [4] → NULL
```

---

# 🚀 Team Setup & 2-Day Development Plan

The project is being developed collaboratively by **3 team members** using GitHub Issues, branches, Pull Requests and AI-assisted development.

### Target

> Complete a fully playable and presentation-ready version within **2 days**.

---

## 👥 Team Assignments

| Member | Branch | Assigned Issues |
|---|---|---|
| Member 1 | `member-1` | #1, #2, #3, #4, #5, #6 |
| Member 2 | `member-2` | #7, #8, #9, #10, #11, #12 |
| Member 3 | `member-3` | #13, #14, #15, #16, #17, #18 |

> Replace the member names/usernames if needed.

**Important:** Every member should understand the overall project, not just their assigned issues.

---

# 💻 Initial Setup — Every Member

### 1. Clone the repository

```bash
git clone https://github.com/sadia-s-shaheen/Classic-snake-game.git
cd Classic-snake-game
```

### 2. Install raylib

Install raylib for your operating system and verify that a basic raylib program can compile and run.

### 3. Switch to your assigned branch

```bash
git checkout member-1
```

Replace `member-1` with your assigned branch.

### 4. Before starting new work

```bash
git checkout main
git pull origin main
git checkout member-X
git merge main
```

---

# 🌱 Git Workflow

For each completed task:

```text
Work on assigned branch
        ↓
Test your changes
        ↓
Commit
        ↓
Push branch
        ↓
Create Pull Request
        ↓
Code Review
        ↓
Merge into main
```

### Commit format

Use clear commits such as:

```bash
git add .
git commit -m "Complete issue #2: implement snake node structure"
git push origin member-1
```

### Rules

- ❌ Do not commit directly to `main`
- ✅ Work on your assigned branch
- ✅ Pull/merge the latest `main` before starting new work
- ✅ Test before pushing
- ✅ Keep commits focused
- ✅ Use Pull Requests for merging

---

# 🐍 Development Roadmap

## Phase 1 — Foundation

| Member | Issues |
|---|---|
| **Member 1** | #1 Setup & raylib → #2 Snake Node Structure |
| **Member 2** | #7 Documentation Structure → #8 Snake Movement |
| **Member 3** | #13 Game Board → #14 Snake Growth |

**Goal:** Window + board + linked-list snake + movement + growth.

---

## Phase 2 — Core Mechanics

| Member | Issues |
|---|---|
| **Member 1** | #3 Food Rendering → #4 Self-Collision |
| **Member 2** | #9 Food Generation → #10 Score System |
| **Member 3** | #15 Wall Collision → #16 Food Collision |

**Goal:** Fully playable basic Snake.

---

## Phase 3 — Game Flow & Polish

| Member | Issues |
|---|---|
| **Member 1** | #5 Game Over Screen → #6 Integration Testing |
| **Member 2** | #11 Start Screen → #12 Documentation & Screenshots |
| **Member 3** | #17 Restart & Game State → #18 Final UI/UX & Bug Testing |

**Goal:** Start → Play → Game Over → Restart.

---

## Phase 4 — Integration

- Push completed branches
- Create Pull Requests → `main`
- Review changes
- Resolve merge conflicts
- Merge completed work
- Run the complete game from `main`

---

## Phase 5 — Final Submission

- [ ] All 18 issues closed
- [ ] Game works from `main`
- [ ] Linked List implementation verified
- [ ] Screenshots added
- [ ] README completed
- [ ] Final bugs tested
- [ ] PPT prepared
- [ ] Demo prepared

---

# 📅 2-Day Target

### Day 1
**Phase 1 + Phase 2**

> Target: **Fully playable basic Snake**

```text
MOVE → EAT FOOD → GROW → SCORE → COLLISION
```

### Day 2
**Phase 3 + Phase 4 + Phase 5**

> Target: **Polished, tested and presentation-ready game**

```text
START → PLAY → GAME OVER → RESTART
```

---

# 🤖 AI-Assisted Development

AI tools may be used for:

- Code generation
- Debugging
- Explanations
- Raylib API guidance
- UI improvements

However, **do not blindly copy generated code**.

Every member should be able to explain:

- `struct`
- Pointers
- `malloc()` / `free()`
- `NULL`
- Linked-list traversal
- Node insertion/deletion
- Game loop
- Keyboard input
- Rendering
- Collision detection
- Game states

Most importantly:

> **Every team member should be able to explain how and why the Linked List is used to implement the Snake.**

---

# 🏁 Definition of Done

The project is complete when:

1. All **18 issues** are closed.
2. All member branches are integrated into `main`.
3. The game builds and runs correctly.
4. The Snake uses a **Singly Linked List**.
5. Core gameplay features work.
6. Screenshots and documentation are complete.
7. The team can explain the implementation during the presentation.
8. The final version is ready for demonstration.
