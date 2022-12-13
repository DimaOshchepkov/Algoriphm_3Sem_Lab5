#include "Header.h"

void CreateMatrix(std::string path)
{
	std::cout << "Input count top\n";
	int top;
	std::cin >> top;

	std::cout << "Input count edge\n";
	int edge;
	std::cin >> edge;

	std::ofstream fout(path);
	fout << top  << '\n';

	std::cout << "Input graph (top - top)\n";

	std::vector<std::vector<int>> matrix(top, std::vector<int>(top));
	for (int i = 0; i < edge; i++)
	{
		int x, y;
		std::cin >> x >> y;
		matrix[x][y] = 1;
		matrix[y][x] = 1;
	}
	
	for (const std::vector<int> row : matrix)
	{
		for (const int el : row)
			fout << el << ' ';
		fout << '\n';
	}
	fout.close();
}

std::vector<std::vector<int>> ReadMatrixFormFile(const std::string& path)
{
	std::ifstream fin(path);

	int size;
	fin >> size;

	std::vector<std::vector<int>> matrix(size, std::vector<int>(size));
	for(int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			fin >> matrix[i][j];

	fin.close();

	return matrix;
}

std::vector<List<int>> ConvertMatrixFromAdjacency(const std::vector<std::vector<int>>& matrix)
{
	std::vector<List<int>> link(matrix.size());
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix.front().size(); j++)
			if (matrix[i][j] != 0) link[i].PushBack(j);

	return link;
}

std::vector<std::vector<int>> ConvertMatrixFromLink(std::vector<List<int>>& link)
{
	std::vector<std::vector<int>> matrix(link.size(), std::vector<int>(link.size()));
	for (int i = 0; i < link.size(); i++)
		for (Node<int>* it = link[i].Begin(); it != link[i].End(); it = it->next)
		{
			matrix[i][it->value] = 1;
			matrix[it->value][i] = 1;
		}

	return matrix;
}

std::vector<List<int>> MainTreeWigth(std::vector<List<int>>& link)
{
	List<int> q;

	std::vector<bool> visited(link.size());

	std::vector<List<int>> mainTree(link.size());
	for (int i = 0; i < link.size(); i++)
		if (!visited[i])
		{
			q.PushBack(i);
			visited[i] = true;
			while (q.Size() != 0)
			{
				int front = q.Front();
				q.PopFront();
				for (Node<int>* it = link[front].Begin(); it != link[front].End(); it = it->next)
				{
					if (!visited[it->value])
					{
						q.PushBack(it->value);
						visited[it->value] = true;
						mainTree[front].PushBack(it->value);
					}

				}
			}
		}

	return mainTree;
}

std::vector<List<int>> MainTreeHeight(std::vector<List<int>>& link)
{
	List<int> q;

	std::vector<bool> visited(link.size());

	std::vector<List<int>> mainTree(link.size());
	for (int i = 0; i < link.size(); i++)
		if (!visited[i])
		{
			q.PushFront(i);
			visited[i] = true;
			while (q.Size() != 0)
			{
				int front = q.Front();
				q.PopFront();
				for (Node<int>* it = link[front].Begin(); it != link[front].End(); it = it->next)
				{
					if (!visited[it->value])
					{
						q.PushFront(it->value);
						visited[it->value] = true;
						mainTree[front].PushBack(it->value);
					}

				}
			}
		}

	return mainTree;
}



