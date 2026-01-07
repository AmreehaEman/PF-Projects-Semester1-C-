# Digital Logic Simulator & Boolean Verifier

A high-performance C++ console application designed to simulate digital logic environments. This tool bridges the gap between theoretical Boolean algebra and practical circuit implementation, featuring real-time logic processing, automated truth table generation, and interactive circuit visualization.

---

## 🛠 Core Technical Capabilities

### 1. Logic Gate Simulation Engine
Low-level implementation of primary and universal logic gates with built-in input sanitization:
* **Primary Gates:** AND, OR, NOT, XOR.
* **Universal Gates:** NAND, NOR.
* **Visual Logic Mapping:** ASCII representation of signal flow from input pins to output.

### 2. Computational Arithmetic Modules
Implementation of binary addition logic used in CPU Arithmetic Logic Units (ALUs):
* **Half-Adder:** Dual-bit addition with Carry-propagation logic.
* **Full-Adder:** Three-input logic (A, B, Carry-In) providing Sum and Carry-Out synchronization.

### 3. Boolean Optimization & Minimization Tools
Advanced educational modules for circuit simplification:
* **Live Law Verification:** Interactive testing for Absorption, Identity, and Idempotent laws.
* **Proof by Comparison:** Side-by-side truth table analysis comparing complex expressions vs. minimized logic.

### 4. Robust Data Validation
* **Type Safety:** Custom `numValidation` layer to prevent buffer overflows or invalid character crashes.
* **Logic Constraints:** Strict bit-level (0, 1) checking to ensure simulation integrity.

---

## 💻 System Architecture

* **Language:** C++
* **Environment:** Windows OS (Console Subsystem)
* **Dependencies:** `iostream`, `windows.h` (Console API for UI/UX coloring), `limits`.
* **Design Pattern:** Functional Modular Programming.

---

## 🚀 Deployment & Installation

### Compilation
Utilize a standard C++ compiler (G++ or MSVC) to build the executable:

```bash
g++ Digital_Logic_Simulator.cpp -o LogicSim
