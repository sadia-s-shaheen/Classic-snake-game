# Classic Snake Game 🐍

A Data Structures-based Snake Game built in **C** using **raylib**, with the snake implemented using a **singly linked list**.

---

## 📌 Project Overview

This project demonstrates the practical application of a **Linked List** through an interactive Snake game.

Each segment of the snake is represented as a node:

```text
Head
 ↓
[Node] → [Node] → [Node] → NULL
```

Each node stores:

- `x` coordinate
- `y` coordinate
- Pointer to the next node

The snake grows dynamically by adding new nodes to the linked list.

---

## 🎯 Problem Statement

Traditional implementations of Snake often use fixed-size arrays to store the snake's body.

However, the snake's length changes continuously during gameplay. This project explores how a **singly linked list** can efficiently represent a dynamically growing snake.

---

## 💡 Proposed Solution

We implement the snake using a dynamically allocated linked list.

During movement:

1. A new node is created at the snake's head.
2. The new node becomes the head.
3. The tail node is removed.
4. When food is eaten, the tail is not removed, causing the snake to grow.

This demonstrates dynamic memory allocation and linked-list operations in a practical application.

---

## ✨ Features

- 🎮 Interactive Snake game
- 🐍 Snake implemented using a singly linked list
- ⬆️⬇️⬅️➡️ Arrow-key movement
- 🍎 Random food generation
- 📈 Dynamic snake growth
- 💯 Score system
- ⚡ Speed increases as the snake grows
- 💥 Wall collision detection
- 💥 Self-collision detection
- 🎬 Start screen
- ☠️ Game-over screen
- 🔄 Restart functionality
- ❌ Safe window closing and memory cleanup

---

## 🛠️ Technology Stack

| Technology | Purpose |
|---|---|
| C | Programming language |
| raylib | Graphics and game window |
| GCC | C compiler |
| Git | Version control |
| GitHub | Collaboration |

---

## 📁 Project Structure

```text
Classic-snake-game/
│
├── src/
│   ├── main.c
│   ├── game.c
│   ├── game.h
│   ├── snake.c
│   ├── snake.h
│   ├── food.c
│   ├── food.h
│   └── config.h
│
├── assets/
├── docs/
├── README.md
└── .gitignore
```

---

## 🧠 Data Structure

### Singly Linked List

The snake is represented as:

```text
HEAD
 ↓
┌─────────────┐
│ x │ y │ next├──────┐
└─────────────┘      ↓
                ┌─────────────┐
                │ x │ y │ next├──────┐
                └─────────────┘      ↓
                                ┌─────────────┐
                                │ x │ y │ NULL│
                                └─────────────┘
```

### Why Linked List?

The snake's size changes during the game, so a linked list allows nodes to be dynamically added and removed.

---

## 👥 Team Members & Responsibilities

| Member | Responsibilities |
|---|---|
| Member 1 | Project setup, snake linked list, food rendering, self-collision, game-over, integration |
| Member 2 | Documentation, movement, food generation, score, start screen |
| Member 3 | Game board, snake growth, wall collision, food collision, restart, UI/UX and testing |

---

# 🚀 Setup Guide for Team Members

This section explains how every team member can set up the project and start contributing.

## 1. Install Git

Download and install Git:

https://git-scm.com/downloads

Verify installation:

```powershell
git --version
```

---

## 2. Clone the Repository

Open PowerShell or Git Bash and navigate to the folder where you want the project.

Then run:

```powershell
git clone https://github.com/sadia-s-shaheen/Classic-snake-game.git
```

Enter the project directory:

```powershell
cd Classic-snake-game
```

---

## 3. Create Your Own Branch

**Do not work directly on `main`.**

First make sure you have the latest version:

```powershell
git checkout main
git pull origin main
```

Create your own branch:

```powershell
git checkout -b your-name
```

For example:

```powershell
git checkout -b ali
```

Verify your branch:

```powershell
git branch
```

You should see:

```text
  main
* ali
```

The `*` indicates your current branch.

---

## 4. Install raylib

The project uses **raylib** for graphics and window management.

Download raylib from:

https://www.raylib.com/

On Windows, use a raylib Windows development package.

For the current project setup, the raylib files are expected at:

```text
C:\raylib\raylib\src
```

You should have:

```text
C:\raylib\raylib\src\raylib.h
C:\raylib\raylib\src\libraylib.a
```

---

## 5. Install GCC

You need a C compiler.

The project currently uses **GCC through MSYS2/UCRT64**.

Verify GCC:

```powershell
gcc --version
```

If GCC is installed correctly, this will display its version information.

---

## 6. Compile the Game

From the project root:

```powershell
gcc src/main.c src/game.c src/snake.c src/food.c -o snake.exe -IC:\raylib\raylib\src -LC:\raylib\raylib\src -lraylib -lopengl32 -lgdi32 -lwinmm
```

If compilation succeeds, `snake.exe` will be created.

> `snake.exe` is ignored by Git and should **not** be committed.

---

## 7. Run the Game

Run:

```powershell
.\snake.exe
```

You should see the Snake start screen.

### Controls

| Key | Action |
|---|---|
| `ENTER` | Start game |
| `↑` | Move up |
| `↓` | Move down |
| `←` | Move left |
| `→` | Move right |
| `R` | Restart after game over |
| `ESC` | Quit |

---

# 🌿 Git Workflow for Team Members

Always work on your own branch.

```text
main
 │
 ├── sadia
 ├── member-2
 └── member-3
```

## Before starting work

Update your local `main`:

```powershell
git checkout main
git pull origin main
```

Then return to your branch:

```powershell
git checkout your-name
```

Merge the latest `main` into your branch:

```powershell
git merge main
```

---

## 💾 Save Your Work

Check what changed:

```powershell
git status
```

Add your changes:

```powershell
git add .
```

Commit:

```powershell
git commit -m "feat: describe your change"
```

For example:

```powershell
git commit -m "feat: add snake movement"
```

---

## ☁️ Push Your Branch

```powershell
git push -u origin your-name
```

For example:

```powershell
git push -u origin ali
```

---

## 🔀 Create a Pull Request

After pushing:

1. Open the GitHub repository.
2. Select your recently pushed branch.
3. Click **Compare & pull request**.
4. Set the base branch to `main`.
5. Set the compare branch to your branch.
6. Describe your changes.
7. Create the Pull Request.
8. Ask the team to review it.
9. Merge it into `main` after review.

---

# ⚠️ Important Git Rules

### ❌ Don't commit directly to `main`

Always work on your own branch.

### ❌ Don't commit generated files

Do not commit:

```text
*.exe
*.o
```

### ✅ Pull before starting new work

```powershell
git checkout main
git pull origin main
```

### ✅ Keep commits focused

Good:

```text
feat: add snake movement
fix: resolve wall collision
docs: update setup instructions
```

Avoid:

```text
changes
final
final final
updated
stuff
```

---

# 🔄 If You Get a Merge Conflict

Check the current state:

```powershell
git status
```

Git will tell you which files have conflicts.

Resolve the conflicting sections, then:

```powershell
git add .
git commit
```

If you are unsure how to resolve a conflict, **stop before force-pushing anything and ask the team.**

---

# 🧪 Definition of Done

- [ ] Raylib window works
- [ ] Snake uses a linked list
- [ ] Snake moves correctly
- [ ] Food generates correctly
- [ ] Snake grows after eating
- [ ] Score works
- [ ] Speed increases with snake length
- [ ] Wall collision works
- [ ] Self-collision works
- [ ] Start screen works
- [ ] Game-over screen works
- [ ] Restart works
- [ ] Memory is properly freed
- [ ] Code compiles without warnings/errors
- [ ] Final version is on `main`
- [ ] Screenshots are added
- [ ] Documentation is complete
- [ ] Presentation is ready

---

# 🤖 AI-Assisted Development

AI tools may be used during development for:

- Debugging
- Understanding C concepts
- Understanding raylib functions
- Generating initial implementation ideas
- Documentation assistance

Every team member should **understand the code they submit** and be able to explain their contribution during the project demonstration.

---

# 📅 Development Plan

### Phase 1 — Foundation

- Raylib setup
- Linked-list snake
- Game board
- Initial snake rendering

### Phase 2 — Core Mechanics

- Movement
- Food generation
- Food rendering
- Snake growth
- Collision detection
- Score

### Phase 3 — Game Flow & Polish

- Start screen
- Game-over screen
- Restart
- UI/UX
- Bug testing

### Phase 4 — Integration

- Merge branches
- Resolve conflicts
- Test complete game
- Capture screenshots
- Finalize documentation

---

# 👨‍💻 Final Goal

The final project demonstrates how a **singly linked list can be applied to a real interactive system**.

```text
Linked List
     ↓
Snake Body
     ↓
Movement
     ↓
Food
     ↓
Dynamic Growth
     ↓
Collision Detection
     ↓
Score + Game State
```

**Built with C + raylib + Data Structures.** 🐍
