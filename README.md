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

# README

## List

This code implements a **Doubly Linked List** in C to manage a student database. It supports sorted insertion by Student ID (AM), searching, modification, and deletion.

---

## Table of Contents

| Section | Folder/File | Description |
|------:|-------------|-------------|
| 1 | `INSTALL.md` | Installation and compilation instructions |
| 2 | `README.md` | Project overview and usage guide |
| 3 | `assign/` | Assignment description images |
| 3.1 | `assign/List.png` | Linked list assignment image (English) |
| 3.2 | `assign/Λίστες.png` | Linked list assignment image (Greek) |
| 4 | `src/` | Source code of the linked list implementation |
| 4.1 | `src/main.c` | Program entry point and example usage of the list |
| 4.2 | `src/list.h` | Linked list structure definitions and function prototypes |
| 4.3 | `src/list.c` | Implementation of linked list operations |

---

## 1. Features

### 1.1 Sorted Insertion
New students are inserted automatically in **ascending order based on AM (Student ID)**.

### 1.2 Doubly Linked Structure
Each node contains:

- `next` pointer → points to the next node  
- `prev` pointer → points to the previous node  

This allows efficient **forward and backward traversal** and simplifies deletion.

### 1.3 Search Capabilities

Students can be searched by:

- **Student ID (AM)** — unique identifier
- **Name**

### 1.4 Data Integrity

The system prevents **duplicate AM values**, ensuring each student ID is unique.

### 1.5 Memory Management

A `destroyList` function releases all allocated memory to **prevent memory leaks**.

---

## 2. Data Structures

The program is built around three main structures.

### 2.1 `student`

Stores the student data:

- `am` - Student ID  
- `name` - Student name  
- `semester` - Current semester  

### 2.2 `node`

Represents a node in the doubly linked list.

Each node contains:

- A `student` record
- Pointer to the **next node**
- Pointer to the **previous node**

### 2.3 `list`

A wrapper structure that stores:

- `head` pointer - first element of the list  
- `tail` pointer - last element of the list  

This simplifies access to both ends of the list.