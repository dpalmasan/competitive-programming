# Competitive Programming

In this repo I practice techniques used for competitive programming. Some code is just reviewing basic data structures and algorithms. I am using `C++` just for fun, this is why in some cases I am just reinventing the wheel to make sure I am having a good understanding of `C++` standard library and the algorithms/data structures I am implementing.

## Testing

For fun, I am using `doctest` framework to write tests. I assume that the library was installed in yout path (this is why I am using `#include <doctest/doctest.h>`). Anyways, in the case of using a non standard directory or having a different compiler configuration, you can do the following to compile the code (assuming the library was installed under `/opt/homebrew/Cellar/doctest/2.4.9/include`):

```
CPLUS_INCLUDE_PATH=/opt/homebrew/Cellar/doctest/2.4.9/include: make dp_examples
```
