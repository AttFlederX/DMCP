#pragma once
#ifndef FUNC_H
#define FUNC_H

#include "lib.h"
#include "Set.h"

void Menu();
void SetsMenu();
void PrintMatrixInRow(float** X, int n, int m);
float** CartesianProduct(Set* X, int n);

#endif