# 📚 get_next_line - Reading Files Line by Line

Hey there! 👋 Welcome to my get_next_line project. Let me tell you about this fascinating journey of creating a function that reads files line by line.

## 🎯 What's This Project About?

Ever wondered how programs read files line by line? Well, that's exactly what I built here! The challenge was to create a function that:
- Reads a line from a file descriptor (could be a file, standard input, or even a network socket!)
- Returns that line as a string
- Works repeatedly - each call gives you the next line
- Handles different buffer sizes efficiently
- Works with both regular and bonus features (like handling multiple file descriptors)

## 🛠️ How I Built It

I tackled this project with a linked list approach, which turned out to be pretty clever! Here's how it works:

1. **The Core Structure**: 
   - Created a linked list where each node stores a chunk of the file (size defined by BUFFER_SIZE)
   - Each node contains the actual content and a pointer to the next chunk

2. **The Reading Process**:
   - Read the file in chunks of BUFFER_SIZE bytes
   - Store these chunks in our linked list
   - Keep reading until we find a newline character or reach the end of file
   - Extract just the right amount of characters to form our line

3. **Memory Management**:
   - Carefully managed memory allocations and frees
   - Used a static variable to remember our position between function calls
   - Made sure there are no memory leaks!

## 🤔 The Tricky Parts

This project had its share of challenges:

1. **Buffer Management**: 
   - Had to figure out how to handle partial reads
   - Dealing with different BUFFER_SIZE values was tricky
   - Making sure we don't lose any characters between calls

2. **Edge Cases**:
   - Empty files
   - Files with no newlines
   - Very long lines
   - End of file situations
   - Invalid file descriptors

3. **Static Variables**:
   - Learning to use static variables to maintain state
   - Making sure the static variable doesn't cause problems with multiple files

## 🎓 What I Learned

This project was a fantastic learning experience:

1. **File Operations**:
   - Deep understanding of how file reading works
   - Better grasp of file descriptors
   - Learning about buffered reading

2. **Data Structures**:
   - Practical experience with linked lists
   - Understanding when and why to use static variables
   - Better memory management skills

3. **Code Organization**:
   - Breaking down complex problems
   - Writing clean, maintainable code
   - Handling edge cases properly

## 💡 How to Use It

```c
#include "get_next_line.h"

int main()
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### 🚀 Bonus Features

I also implemented some cool bonus features:
- Handling multiple file descriptors simultaneously
- Using a single static variable
- Same smooth performance with different BUFFER_SIZE values

## 🔍 Final Thoughts

This project really opened my eyes to how file I/O works at a lower level. It's one thing to use `fgets` or similar functions, but building this from scratch gave me a whole new appreciation for file handling in C.

The skills I learned here - especially about memory management and linked lists - have been super helpful in later projects. Plus, now I have my own function for reading files line by line! 😎

---
*Built with ❤️ and lots of coffee at 42 School*
