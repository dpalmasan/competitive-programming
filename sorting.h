#pragma once

#include <vector>

void bubble_sort(int*, const std::size_t&);

void __sort(int*, const std::size_t&, const std::size_t&);
void __merge(int* arr, const std::size_t&, const std::size_t&, const std::size_t&);
void merge_sort(int*, const std::size_t&);