# Codebase Audit & Improvement Report

## Executive Summary
This report summarizes a comprehensive codebase audit and refinement to improve code quality, enforce C++ standards, and enhance performance across basic implementations, algorithms, and data structures. Existing functionality was completely preserved.

## Comprehensive Audit Details

### 1. Narrowing Conversions Fixed
* **Why the change was needed:** `arr.size()` returns a `size_t`, which was implicitly narrowing to `int` when performing arithmetic and assigning values. `std::count_if` returns a `ptrdiff_t` that was similarly being narrowed implicitly.
* **Impact:** Eliminates compiler warnings about implicit narrowing, improving portability and type safety without breaking API behavior.
* **Trade-offs:** Makes the code slightly more verbose.
* **Affected files:** `basics/dsa1.cpp`
* **Before/After behavior:** Before, `size_t` implicitly converted to `int`. After, `static_cast<int>()` makes conversions explicit.

### 2. Move Semantics Added to Data Structures
* **Why the change was needed:** When inserting dynamically allocated or heavy objects, passing by const reference always incurs a deep copy. Adding rvalue-reference overloads allows `std::move` to avoid unnecessary memory allocations.
* **Impact:** Substantial performance improvement for complex types stored in `Queue` and `Stack`. Logging statements (e.g., `std::cout`) were carefully placed *before* the move operation to avoid printing moved-from states. Explicitly included `<utility>`.
* **Trade-offs:** Slightly increases boilerplate by duplicating insertion functions for lvalue and rvalue references.
* **Affected files:** `data_structures/stack.cpp`, `data_structures/queue.cpp`
* **Before/After behavior:** Before, `push`/`enqueue` only took `const T&`. After, they additionally accept `T&&` to move elements.

### 3. Compile-Time Validation (static_assert) Added
* **Why the change was needed:** The `Stack` and `Queue` data structures define a generic non-type template parameter for capacity `msize`. If `msize` equals `0`, operations like the modulo arithmetic in `Queue` or basic functionality would break silently or cause runtime errors.
* **Impact:** Enforces strict constraints safely at compile time rather than relying on runtime errors.
* **Trade-offs:** Prevents instantiation of zero-capacity data structures.
* **Affected files:** `data_structures/stack.cpp`, `data_structures/queue.cpp`
* **Before/After behavior:** Before, `Stack<int, 0>` could be instantiated. After, it raises a compile-time assertion.

### 4. Query Method Added to Data Structures
* **Why the change was needed:** Existing data structures lacked a method to easily retrieve the current number of elements without inspecting their internal state.
* **Impact:** Provides an accessible `[[nodiscard]] size_t getSize() const` method to safely query capacity.
* **Trade-offs:** Minor increase in code volume.
* **Affected files:** `data_structures/stack.cpp`, `data_structures/queue.cpp`
* **Before/After behavior:** Before, only `isEmpty()` existed. After, both `isEmpty()` and `getSize()` are present.

### 5. Sorting Optimizations & Explicit Types
* **Why the change was needed:** The `insertionSort` algorithm involved deep copies when moving elements array-wide. Mixed conversion warnings between `size_t` and `std::ptrdiff_t` existed. And `<utility>` was implicitly relied upon for `std::swap`.
* **Impact:** Avoids redundant memory copying inside the tight inner loop of the insertion sort using `std::move`. Type safety is improved through explicit casts. `<utility>` guarantees reliable compilation across all conformant compilers.
* **Trade-offs:** Adds slight cognitive overhead to the algorithm reading.
* **Affected files:** `algorithms/insertion_sort.cpp`, `algorithms/bubblesort.cpp`, `algorithms/selectionsort.cpp`
* **Before/After behavior:** Before, `insertionSort` used `=` copy assignment. After, it uses `std::move()`. Implicit types were cast properly.

---

## Summaries

### Critical issues fixed
* Resolved narrowing conversion warnings in `dsa1.cpp` by explicitly casting `size_t` to `int`.
* Prevented silent logical bugs regarding zero-size templates with compile-time assertions in `Queue` and `Stack`.
* Fixed missing explicit `#include <utility>` headers in algorithms heavily relying on `std::move` and `std::swap`.

### Performance improvements
* Added rvalue reference insertion overloads (`push` and `enqueue`) in `Stack` and `Queue`, avoiding costly copy operations on complex types via `std::move`.
* Replaced copy assignment with `std::move` within the `insertionSort` inner loop for shifting array elements, significantly speeding up the sorting of non-primitive types.

### Code quality improvements
* Enforced exact data types for explicit casting of indices (e.g., `static_cast<std::ptrdiff_t>()`) to safely manage negative loop boundaries.
* Addressed readability by enforcing `[[nodiscard]]` accurately.
* Documented operations accurately in sync with modern standards.

### Security improvements
* Adding `static_assert(msize > 0)` acts as an input validation at compile time, eliminating undefined behavior (e.g., division by zero in `Queue` indexing arithmetic).

### Design improvements
* Introduced uniform `getSize()` query functions to improve the usability and robustness of standard data structures without compromising their strictly encapsulated state.

### Technical debt removed
* Replaced implicit conversions with explicitly casted data types.
* Stopped depending on implicit standard library inclusion for critical algorithmic logic.

### Remaining recommendations
* Transition `Queue` bounds logic away from raw indices arrays toward circular buffer dynamic allocation to prevent heap fragmentation.
* Implement robust unit testing frameworks (like Catch2 or GoogleTest) to scale test assertions beyond rudimentary `cassert`.
* Add C++20 Concepts constraint checks on template arguments (e.g., `requires std::totally_ordered<T>`).

### Overall project health score (0–100)
**95/100** - The codebase fundamentally functions cleanly and enforces strong basic principles. Remaining issues rely purely on adopting newer standardization methods, optimizing specific dynamic paradigms, and formalizing the testing framework.

### Priority list of future improvements
1. **Implement Framework Testing:** Migrate to Catch2/GoogleTest for advanced test verification (especially useful for Exception testing).
2. **Template Concepts (C++20):** Move to C++20 for stronger generic input constraints.
3. **Advanced Structures:** Implement Hash Maps, Trees, and priority queues to make the repository more robust and widely applicable.
