<p align="center">
  <img src="https://www.especial.gr/wp-content/uploads/2019/03/panepisthmio-dut-attikhs.png" alt="UNIWA" width="150"/>
</p>

<p align="center">
  <strong>UNIVERSITY OF WEST ATTICA</strong><br>
  SCHOOL OF ENGINEERING<br>
  DEPARTMENT OF COMPUTER ENGINEERING AND INFORMATICS
</p>

<p align="center">
  <a href="https://www.uniwa.gr" target="_blank">University of West Attica</a> ·
  <a href="https://ice.uniwa.gr" target="_blank">Department of Computer Engineering and Informatics</a>
</p>

<hr/>

<p align="center">
  <strong>Data Structures</strong>
</p>

<h1 align="center" style="letter-spacing: 1px;">
  List
</h1>

<p align="center">
  <strong>Vasileios Evangelos Athanasiou</strong><br>
  Student ID: 19390005
</p>

<p align="center">
  <a href="https://github.com/Ath21" target="_blank">GitHub</a> ·
  <a href="https://www.linkedin.com/in/vasilis-athanasiou-7036b53a4/" target="_blank">LinkedIn</a>
</p>

<hr>

<p align="center">
  <strong>Supervision</strong>
</p>

<p align="center">
  Supervisor: Georgios Bardis, Assistant Professor
</p>
<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/georgios-bardis/" target="_blank">UNIWA Profile</a>
</p>

<p align="center">
  Co-supervisor: Georgios Meletiou, Laboratory Teaching Staff<br>
</p>

<p align="center">
  <a href="https://ice.uniwa.gr/en/emd_person/georgios-meletiou/" target="_blank">UNIWA Profile</a>
</p>

<p align="center">
  Co-supervisor: Georgios Tselikis, Postdoctoral Researcher
</p>
<p align="center">
  <a href="https://eee.uniwa.gr/el/25-viografiko/1139-giorgos-tselikis" target="_blank">UNIWA Profile</a> ·
  <a href="https://www.linkedin.com/in/george-tselikis-5a7ba84/" target="_blank">LinkedIn</a>
</p>

</hr>

---

<p align="center">
  Athens, November 2022
</p>

---

<p align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQtD5WRS4iJ4JJ_vf2r20S9ELHQl9p_-tdNxA&s" width="250"/>
</p>

---

# INSTALL

## List

This guide explains how to set up, build, and run the project on your local machine.

---

## 1. How to Compile and Run

### 1.1 Clone the Repository

Open your terminal or command prompt and run:

```bash
git clone https://github.com/Data-Structures-aka-Uniwa/List.git
cd List/src
```

### 1.2 Compilation

Since the project uses multiple source files, compile using:

```bash
gcc -o student_manager main.c list.c
```

### 1.3 Execution
Run the program with:
```bash
./student_manager
```

---

## 2. Functionality Overview
| Function        | Description                                                        |
|----------------|--------------------------------------------------------------------|
| initList        | Initializes the list by setting head and tail pointers to NULL     |
| insertStudent   | Inserts a new student in sorted order based on AM                  |
| deleteStudent   | Removes a student by ID and reconnects neighboring nodes           |
| searchByAM      | Searches for a student using their ID                              |
| modifyStudent   | Updates student data and reorders the list if AM changes           |
| printBySemester | Displays students belonging to a specific semester                 |

---

## 3. Important Note on deleteStudent
The provided implementation contains a logic bug in pointer reassignment.

### 3.1 Incorrect Code
```c
// Current code
if (n->prev) n->prev = n->next;
if (n->next) n->next = n->prev;
```

This incorrectly modifies the node pointers instead of updating the neighboring nodes.

### 3.2 Correct Implementation
```c
if (n->prev) n->prev->next = n->next;
if (n->next) n->next->prev = n->prev;
```

This properly reconnects the surrounding nodes and prevents breaking the linked list chain.