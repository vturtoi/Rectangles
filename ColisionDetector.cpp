#include "stdafx.h"
#include "ColisionDetector.h"
#include <stack>

ColisionDetector::ColisionDetector()
{
}


ColisionDetector::~ColisionDetector()
{
	for (int i = 0; i < matrixSize; i++)
	{
		if (matrix[i] != NULL)
		{
			delete[] matrix[i];
			matrix[i] = NULL;
		}
	}
	if (matrix != NULL)
	{
		delete[] matrix;
		matrix = NULL;
	}
}

void ColisionDetector::initMatrix(int dimension)
{
	matrix = new PInt[dimension];
	for (int i = 0; i < dimension; i++)
	{
		matrix[i] = new int[dimension];
	}
}

void ColisionDetector::findIntersections(char * fileName)
{
	rectangles = fileParser.loadRectangles(fileName);
	matrixSize = rectangles.size();
	initMatrix(matrixSize);
	for (int i = 0; i < matrixSize-1 ; i++)
	{
		Rectangle &r = rectangles.at(i);
		matrix[i][i] = 1;
		for (int j = i + 1; j < matrixSize; j++)
		{
			Rectangle crtRectangle = rectangles.at(j);
			Rectangle intersect = r.intersection(crtRectangle);
			if (intersect.getX() != -1)
			{
				printf(" rectangle %d intersect rectangle %d with x=%d y=%d w=%d h=%d\n", i, j, intersect.getX(), intersect.getY(),intersect.getW(), intersect.getH());
				matrix[i][j] = 1;
				matrix[j][i] = 1;
			}
			else
			{
				matrix[i][j] = matrix[j][i] = 0;
			}
		}
	}

	std::vector<int> arr;
	std::list<int> l;
	for (int i = 0; i < matrixSize; i++)
	{
		int* pLine = matrix[i];
		int j = 1;
		while (j < matrixSize)
		{
			
			if (i >= j)
			{
				j++;
				continue;
			}

			if (matrix[i][j] != 0)
			{
				arr.push_back(j);
			}
			j++;
		}
		for (int k = 2; k <= arr.size(); k++)
		{
			subset(i, arr, arr.size(), k, 0, l);
		}
		arr.clear();
	}

}

void ColisionDetector::subset(int root, std::vector<int> arr, int totalSize, int partitionSize, int index, std::list<int>& l)
{
	if (partitionSize == 0)
	{
		printSet(root,l);
		printf("\n");
		return;
	}
	for (int i = index; i < totalSize; i++)
	{
		l.push_back(arr.at(i));
		subset(root,arr, totalSize, partitionSize - 1, i+1 , l);
		l.pop_back();
	}
}

void ColisionDetector::printSet(int root, std::list<int> l)
{
	std::list<int>::iterator itr = l.begin();
	Rectangle listIntersection = rectangles.at(root);
	
	while (itr != l.end())
	{
		listIntersection = listIntersection.intersection(rectangles.at(*itr));
		if (listIntersection.getX() == -1)
		{
			return;
		}
		itr++;
	}

	printf("rectangle %d intersects rectangles ", root);
	for (itr = l.begin(); itr != l.end(); itr++)
	{
		printf(" %d ", *itr);
	}
	printf("with values x = %d y = %d w = %d h = %d\n", listIntersection.getX(), listIntersection.getY(), listIntersection.getW(), listIntersection.getH());
}

