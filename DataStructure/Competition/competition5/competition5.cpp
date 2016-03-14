#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int input[1000000] = {0};
int output[1000000] = {0};
int report[1000000] = {0};
int inputtemp1[100] = {0};
int inputtemp2[1000000] = {0};
int outputtemp1[100] = {0};
int outputtemp2[1000000] = {0};

int main()
{
	size_t counterIn = 0;
	size_t counterOut = 0;
	size_t counterReport = 0;
	size_t count;
	size_t codes;
	size_t n;
	size_t counter = 0;

	string s = "";

	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> s >> count;
		counterIn = 0;
		counterOut = 0;
		for (size_t i = 0; i < count; i++)
		{
			cin >> codes;
			if (s == "in")
			{
				inputtemp1[counterIn] = codes;
				counterIn++;
			}
			else if (s == "out")
			{
				if (codes == 6)
					int e = 0;
				outputtemp1[counterOut] = codes;
				counterOut++;
			}
			else if (s == "report")
			{
				report[counterReport] = codes;
				counterReport++;
			}
		}
		int p = 0;
		int q = 0;
		counter = 0;
		if (s == "in")
		{
			while (p < 100 && q<1000000)
			{
				if (input[0] != 0)
				{
					if (input[q] != 0 && inputtemp1[p] != 0)
					{
						if (inputtemp1[p] > input[q])
						{
							inputtemp2[counter] = input[q];
							counter++;
							q++;
						}
						else
						{
							inputtemp2[counter] = inputtemp1[p];
							counter++;
							p++;
						}
					}
					else
					{
						break;
					}
				}
				else
				{
					if (inputtemp1[p] != 0)
					{
						inputtemp2[counter] = inputtemp1[p];
						p++;
						counter++;
					}
					else
					{
						break;
					}
				}
			}

			while (p < 100)
			{
				if (inputtemp1[p] != 0)
				{
					inputtemp2[counter] = inputtemp1[p];
					p++;
					counter++;
				}
				else
					break;
			}
			while (q < 1000000)
			{
				if (input[q] != 0)
				{
					inputtemp2[counter] = input[q];
					q++;
					counter++;
				}
				else
					break;
			}


			bool b = true;
			for (size_t l = 0; l < 1000000; l++)
			{
				if (input[l] != 0)
					input[l] = 0;
				else
					break;
			}
			for (size_t s = 0; s < 1000000; s++)
			{
				if (inputtemp2[s] != 0)
				{
					input[s] = inputtemp2[s];
					inputtemp2[s] = 0;
				}
				else
					b = false;
				if (inputtemp1[s] != 0)
					inputtemp1[s] = 0;
				else if (b == false){
					counterIn = 0;
					break;
				}
			}
		}

		p = 0;
		q = 0;
		counter = 0;
		if (s == "out")
		{
			while (p < 100 && q<1000000)
			{
				if (output[0] != 0)
				{
					if (output[q] != 0 && outputtemp1[p] != 0)
					{
						if (outputtemp1[p] > output[q])
						{
							outputtemp2[counter] = output[q];
							counter++;
							q++;
						}
						else if (outputtemp1[p] < output[q])
						{
							outputtemp2[counter] = outputtemp1[p];
							counter++;
							p++;
						}
					}
					else
						break;
				}
				else
				{
					if (outputtemp1[p] != 0)
					{
						outputtemp2[counter] = outputtemp1[p];
						counter++;
						p++;
					}
					else
						break;
				}
			}

			while (p < 100)
			{
				if (outputtemp1[p] != 0)
				{
					outputtemp2[counter] = outputtemp1[p];
					p++;
					counter++;
				}
				else
					break;
			}
			while (q < 1000000)
			{
				if (output[q] != 0)
				{
					outputtemp2[counter] = output[q];
					q++;
					counter++;
				}
				else
					break;
			}

			for (size_t h = 0; h < 1000000; h++)
			{
				if (output[h] != 0)
					output[h] = 0;
				else
					break;
			}
			bool b = true;
			for (size_t s = 0; s < 1000000; s++)
			{
				if (outputtemp2[s] != 0)
				{
					output[s] = outputtemp2[s];
					outputtemp2[s] = 0;
				}
				else
					b = false;
				if (outputtemp1[s] != 0)
					outputtemp1[s] = 0;
				else if (b == false)
				{
					counterOut = 0;
					break;
				}
			}
		}

	}
	size_t p = 0; // for report
	size_t q = 0; // for input
	while (p < 1000000)
	{
		if (report[p] != 0 && input[p] != 0)
		{
			if (report[p] == input[q])
			{
				input[q] = -1;
				p++;
				q++;
			}
			else if (report[p] > input[q])
				q++;
			else
				p++;
		}
		else
			break;
	}

	p = 0; // for input
	q = 0; // for output
	while (p<1000000 && q<1000000)
	{
		if (input[p] != 0 && output[q] != 0)
		{
			if (input[p] == output[q])
			{
				input[p] = -1;
				p++;
				q++;
			}
			else if (input[p] > output[q])
				q++;
			else
				p++;
		}
		else
			break;
	}

	counter = 0;
	for (size_t i = 0; i < 1000000; i++)
	{
		if (input[i] != 0)
		{
			if (input[i] != -1)
				counter++;
		}
		else
			break;
	}
	cout << counter << endl;
	for (size_t i = 0; i <1000000; i++)
	{
		if (input[i] != 0)
		{
			if (input[i] != -1)
				cout << input[i] << " ";
		}
		else
			break;
	}


	return 0;
}