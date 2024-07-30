Comprehensive Report on the Implementation of an E++ Expression Evaluator with AVL Trees

Introduction:
This comprehensive report delves into the detailed design and implementation of an expression evaluator for the E++ programming language.
The project's primary goal is the creation of a sophisticated software component capable of interpreting and computing the results of mathematical, logical, or symbolic expressions. 
E++ introduces a syntax that promotes clarity, emphasizing declaration before use and enforcing immutability to enhance program structure and reduce error potential in the provided programs.

Syntax and Semantics:
The syntax of E++ revolves around two fundamental statement types: variable assignment and returning a value.
Variables must be assigned before use, and each variable is restricted to a single assignment, enforcing a clear program structure and minimizing the potential for errors.
This syntax ensures that the programs conform to the language's rules and contributes to the reliability of the expression evaluator.

UnlimitedInt Class:
Central to the implementation is the UnlimitedInt class, a custom integer data type designed to handle integers of arbitrary size.
Unlike standard integer types with fixed ranges, UnlimitedInt employs dynamic memory allocation and deallocation to facilitate the representation of extremely large or precise integer values.
This class serves as a fundamental building block for the expression evaluator, providing the necessary groundwork for unlimited precision arithmetic.

UnlimitedRational Class:
Building upon the capabilities of UnlimitedInt, the UnlimitedRational class extends the concept of rational numbers.
Represented as p/q, where p and q are coprime integers, and q is non-zero, this class leverages the unlimited precision capabilities of UnlimitedInt.
It offers a robust solution for scenarios where standard floating-point representations might suffer from precision loss, enabling the handling of complex calculations with unprecedented accuracy.

Parser and Parse Tree:
The parser is a crucial component that converts each statement in an E++ program into a unique parse tree.
This tree structure captures the program's organization, facilitating syntactic checks and ensuring adherence to the language's rules.
The parse tree's uniqueness is guaranteed by specific conditions, which dictate the hierarchical arrangement of nodes, providing a foundation for correct expression evaluation.
![image](https://github.com/user-attachments/assets/a7d3081b-5c50-4124-839e-5ea1d0850f6e)

AVL Trees:
Assignment 4 harnesses the power of AVL trees to implement an efficient expression evaluator.
AVL trees, known for their balanced structure, facilitate rapid retrieval and manipulation of variables and constants within expressions. 
This balanced structure optimizes performance, ensuring that the expression evaluation process is both accurate and efficient, even for complex and extensive programs.

In summary, the implementation of the E++ expression evaluator in Assignment 4 exemplifies a meticulous integration of dynamic memory management, unlimited precision arithmetic, and a balanced data structure through AVL trees.
The combination of a carefully designed syntax, adherence to semantic rules, a unique parse tree representation, and the use of custom integer and rational classes collectively enhances the robustness, correctness, and efficiency of the E++ expression evaluator.
The resulting software component is well-equipped to handle a wide range of mathematical expressions with precision and reliability.





