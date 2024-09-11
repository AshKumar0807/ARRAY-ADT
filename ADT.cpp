#include <iostream>
#include<algorithm>
using namespace std;
class test
{
public:
	int *A;
	int size;
	int length;
};
void
input (test * d)
{
	cout << "Enter the elements : " << endl;
	for (int i = 0; i < d->length; i++)
	{
		cin >> d->A[i];			//Element input
	}
}

void
swap (int *x, int *y)			//swap function
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


void bubble_sort(test * d)
{
	int i,j,temp;
	for(i=0; i<d->length-1; i++)
	{
		for(j=0; j<d->length-i-1; j++)
		{
			if(d->A[j]>d->A[j+1])
			{
				temp=d->A[j];
				d->A[j]=d->A[j+1];
				d->A[j+1]=temp;
			}
		}
	}
	cout<<" sort hogya :]\n";
}

void insertion_sort(test * d)
{
	int i,j,temp;
	for(i=1; i< d->length+1; i++)
	{
		temp=d->A[i];
		j=i-1;
		while(j>=0 && d->A[j]>temp)
		{
			d->A[j+1]=d->A[j];
			j--;
		}
		d->A[j+1]=temp;
	}
	cout<<"Yeh sorting bhi hogya :]";
}

void
insert (test * d, int index, int x)
{
	int i;
	if (index >= 0 && d->length < d->size)	//checking for memory space
	{
		for (i = d->length; i > index; i--)
		{
			d->A[i] = d->A[i - 1];	//shifting the elements to make space at given Index
		}
		if (index != i)
		{
			cout << "Invalid index";	//if the given index is invalid
		}
		else
		{
			d->A[index] = x;		//inserting the Element
			d->length++;			//incrementing length
			cout << "Element has been inserted.";
		}
	}
	else
	{
		cout << "No memory space available!";
	}
}

bool s(test d)
{
	{
		int c = 0;
		for (int i = 0; i < d.length - 1; i++)
		{
			if (d.A[i] > d.A[i + 1])
			{
				c++;
			}
		}
		if (c != 0)
		{
			return false;
		}
		else
		{
			return true;
		}

	}
}

void
append (test * d, int x)
{
	if (d->length < d->size)		//checking for memory space
	{
		d->A[d->length] = x;		//inserting Element
		d->length++;				//incrementing length
		cout << "Element has been Added.";
	}
	else							//when no space available
	{
		cout << "No memory space available!";
	}
}

int
searchLinear (test * d, int key)
{
	for (int i = 0; i < d->length; i++)
	{
		if (key == d->A[i])
		{
			swap (&d->A[i], &d->A[0]);	//swaping Elements
			cout << "Element found at Index : " << 0;
			return 0;
		}
	}
	cout << "Element not found!!";
	return -1;
}

int
SearchBinary (test d, int key)
{
	if(s(d)!=true)
	{
		cout<<"Array is not sorted, search op not available!";
		return -1;
	}

	int mid;
	int l = 0;					//low
	int h = d.length - 1;			//high
	while (l <= h)
	{
		mid = (l + h) / 2;		//calculating mid
		if (key == d.A[mid])
		{
			cout << "Element found at index : " << mid;
			return mid;
		}
		else if (key < d.A[mid])
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << "\nElement not found!!";
	return -1;
}

int
Get (test d, int index)
{
	if (index >= 0 && index < d.length)
	{
		return d.A[index];		//returning element
	}
	else
	{
		return -1;				//when element not found
	}
}

void
Set (test * d, int index, int x)
{
	if (index >= 0 && index < d->length)
	{
		d->A[index] = x;			//Setting element
		cout << "\nElement has been set.";
	}
}

int
sum (test d)
{
	int s = 0;
	int i;
	for (i = 0; i < d.length; i++)
	{
		s += d.A[i];
	}
	return s;
}

float
Avg (test d)
{
	return (float) sum (d) / d.length;
}

int
Max (test d)
{
	int max = d.A[0];
	for (int i = 1; i < d.length; i++)
	{
		if (d.A[i] > max)
		{
			max = d.A[i];
		}
	}
	return max;
}

int
Min (test d)
{
	int min = d.A[0];
	for (int i = 1; i < d.length; i++)
	{
		if (d.A[i] < min)
		{
			min = d.A[i];
		}
	}
	return min;
}

void
reverse1 (test * d)				//reverse function 1
{
	int *B;
	int i, j;
	B = new int[d->length];
	for (i = d->length - 1, j = 0; i >= 0; i--, j++)
	{
		B[j] = d->A[i];
	}
	for (i = 0; i < d->length; i++)
	{
		d->A[i] = B[i];
	}
	cout << "\nArray has been reversed!";
}

void
reverse2 (test * d)				//reverse function 2
{
	int i, j;
	for (i = 0, j = d->length - 1; i < j; i++, j--)
	{
		swap (&d->A[i], &d->A[j]);
	}
	cout << "\nArray has been reversed!";
}

void
leftshift_rotate (test * d)
{
	int temp, i;
	temp = d->A[0];
	for (i = 0; i < d->length - 1; i++)
	{
		d->A[i] = d->A[i + 1];
	}
	d->A[d->length - 1] = temp;
	cout << "\nShifting and rotation is done!";
}

void
rightshift_rotate (test * d)
{
	int temp, i;
	temp = d->A[d->length - 1];
	for (i = d->length - 1; i > 0; i--)
	{

		d->A[i] = d->A[i - 1];
	}
	d->A[0] = temp;
	cout << "\nShifting and rotation is done!";
}

int
Delete (test * d, int ind)
{
	int x, i;
	if (ind >= 0 && ind < d->length)
	{
		x = d->A[ind];			//deleting element
		for (i = ind; i < d->length - 1; i++)
		{
			d->A[i] = d->A[i + 1];	//shifting elements one space back
		}
		d->length--;
		cout << "Element " << x << " has been deleted.";
		return x;
	}
	else
	{
		cout << "Index error!";	//when index in not within the range
		return 0;
	}
}

void
sorted_insert (test * d, int x)
{
	int i = d->length;
	if (d->length < d->size)
	{
		while (i >= 0 && d->A[i - 1] > x)
		{
			d->A[i] = d->A[i - 1];
			i--;
		}
		d->A[i] = x;
		d->length++;
		cout << "\nElement has been inserted!";
	}
	else
	{
		cout << "No space available!";
	}
}


void
sorted (test d)
{
	int c = 0;
	for (int i = 0; i < d.length - 1; i++)
	{
		if (d.A[i] > d.A[i + 1])
		{
			c++;
		}
	}
	if (c != 0)
	{
		cout << "\nArray is not sorted!\n";
	}
	else
	{
		cout << "\nArray is sorted!\n";
	}
	cout<<"sorted";

}

void
rearrange (test * d)
{
	int i = 0;
	int j = d->length - 1;
	while (i < j)
	{
		while (d->A[i] < 0)
		{
			i++;
		}
		while (d->A[j] >= 0)
		{
			j--;
		}

		if (i < j)
		{
			swap (&d->A[i], &d->A[j]);
		}
	}
	cout << "\nOperation is done!\n";
}

void
Merge (test * arr, test * arr2, test * arr3)
{
	int i = 0, j = 0, k = 0;
	arr3->A = new int[arr->size + arr2->size];
	while (i < arr->length && j < arr2->length)
	{
		if (arr->A[i] < arr2->A[j])
		{
			arr3->A[k++] = arr->A[i++];
		}
		else
		{
			arr3->A[k++] = arr2->A[j++];
		}
	}
	for (; i < arr->length; i++)
	{
		arr3->A[k++] = arr->A[i];
	}
	for (; j < arr2->length; j++)
	{
		arr3->A[k++] = arr2->A[j];
	}
	arr3->length = arr->length + arr2->length;
	arr3->size = arr->size + arr2->size;
	cout << "\nArrays have been merged! ";
	cout << "\nArray: ";
	for (int k = 0; k < arr3->length; k++)
	{
		cout << arr3->A[k] << " ";	//traversing through the array and printing it's Elements
	}
}

void
Union (test * arr, test * arr2, test * arr3)
{
	int i = 0, j = 0, k = 0;
	arr3->A = new int[arr->size + arr2->size];
	while (i < arr->length && j < arr2->length)
	{
		if (arr->A[i] < arr2->A[j])
		{
			arr3->A[k++] = arr->A[i++];
		}
		else if (arr2->A[j] < arr->A[i])
		{
			arr3->A[k++] = arr2->A[j++];
		}
		else
		{
			arr3->A[k++] = arr->A[i++];	//if both Elements are equal copy any one
			j++;
		}
	}
	for (; i < arr->length; i++)
	{
		arr3->A[k++] = arr->A[i];
	}
	for (; j < arr2->length; j++)
	{
		arr3->A[k++] = arr2->A[j];
	}
	arr3->length = k;
	arr3->size = arr->size + arr2->size;
	cout << "\nUnion of arrays: ";
	for (int k = 0; k < arr3->length; k++)
	{
		cout << arr3->A[k] << " ";	//traversing through the array and printing it's Elements
	}
}

void
intersection (test * arr, test * arr2, test * arr3)
{
	int i = 0, j = 0, k = 0;
	arr3->A = new int[arr->size + arr2->size];
	while (i < arr->length && j < arr2->length)
	{
		if (arr->A[i] < arr2->A[j])
		{
			i++;
		}
		else if (arr2->A[j] < arr->A[i])
		{
			j++;
		}
		else
		{
			arr3->A[k++] = arr->A[i++];	//if both Elements are equal copy any one
			j++;
		}
	}

	arr3->length = k;
	arr3->size = arr->size + arr2->size;
	cout << "\nInteraction of arrays: ";
	for (int k = 0; k < arr3->length; k++)
	{
		cout << arr3->A[k] << " ";	//traversing through the array and printing it's Elements
	}
}

void
differance (test * arr, test * arr2, test * arr3)
{
	int i = 0, j = 0, k = 0;
	arr3->A = new int[arr->size + arr2->size];
	while (i < arr->length && j < arr2->length)
	{
		if (arr->A[i] < arr2->A[j])
		{
			arr3->A[k++] = arr->A[i++];
		}
		else if (arr2->A[j] < arr->A[i])
		{
			j++;
		}
		else
		{
			i++;					//if both Elements are equal copy any one
			j++;
		}
	}
	for (; i < arr->length; i++)
	{
		arr3->A[k++] = arr->A[i];
	}
	arr3->length = k;
	arr3->size = arr->size + arr2->size;
	cout << "\nInteraction of arrays: ";
	for (int k = 0; k < arr3->length; k++)
	{
		cout << arr3->A[k] << " ";	//traversing through the array and printing it's Elements
	}
}

void
display (test d)
{
	cout << "\nArray: ";
	for (int i = 0; i < d.length; i++)
	{
		cout << d.A[i] << " ";	//traversing through the array and printing it's Elements
	}
}


void
opermenu (test d, test d2, test d3)
{
	int Index, temp, key, Element, low, high, oper = 0, re;
	cout << "\n[__MENU__]: ";
	cout << "\n[1]Insert An Element.";
	cout << "\n[2]Append an Element.";
	cout << "\n[3]Delete an Element.";
	cout << "\n[4]Linear Search an Element.";
	cout << "\n[5]Binary Search an Element.";
	cout << "\n[6]Set an Element.";
	cout << "\n[7]Get an Element.";
	cout << "\n[8]Sum of Elements.";
	cout << "\n[9]Avg of Elements.";
	cout << "\n[10]Max.";
	cout << "\n[11]Min.";
	cout << "\n[12]Reverse the array.";
	cout << "\n[13]Shift & Rotate.";
	cout << "\n[14]Sorted Insert.";
	cout << "\n[15]Check if Array is sorted.";
	cout << "\n[16]Re-Arrange Array(-ve/+ve).";
	cout << "\n[17]Merge arrays.";
	cout << "\n[18]Union of arrays.";
	cout << "\n[19]Intersection of arrays.";
	cout << "\n[20]Differance of arrays.";
	cout << "\n[21]Bubble Sort.";
	cout << "\n[22]Insertion Sort.";
	cout << "\n[23]Display the array.";
	cout << "\nChoose an operation: ";
	cin >> oper;

	switch (oper)
	{
	case 1:
		cout << "Enter the Index and Element: ";
		cin >> Index >> Element;
		insert (&d, Index, Element);	//Insert operation
		break;
	case 2:
		cout << "Enter the Element: ";
		cin >> Element;
		append (&d, Element);		//Append operation
		break;
	case 3:
		cout << "Enter the Index: ";
		cin >> Index;
		Delete (&d, Index);		//Delete operation
		break;
	case 4:
		cout << "Enter the key: ";
		cin >> key;
		searchLinear (&d, key);	// Linear search operation
		break;
	case 5:
		cout << "Enter the key:";
		cin >> key;
		SearchBinary (d, key);	//Binary search operation
		break;
	case 6:
		cout << "Enter the Index and Element: ";
		cin >> Index >> Element;
		Set (&d, Index, Element);	//Set element operation
		break;
	case 7:
		cout << "Enter the Index: ";
		cin >> Index;
		cout << "Element: " << Get (d, Index);	//Get element operation
		break;
	case 8:
		cout << "Sum of Elements: " << sum (d);	//Sum operation
		break;
	case 9:
		cout << "Average of Elements: " << Avg (d);	//Avg operation
		break;
	case 10:
		cout << "Max: " << Max (d);	//Max operation
		break;
	case 11:
		cout << "Min: " << Min (d);	//Min operation
		break;
	case 12:
		cout << "\n[1]Reverse array through auxilary array.";	//reverse1
		cout << "\n[2]Scan and Swap array.";	//reverse2
		cout <<
		     "\n[NOTE: I'D RECOMMEND USING SECOND OPTION, IT'S MUCH QUICKER!!]";
		cout << "\nChoose: ";
		cin >> re;
		if (re == 1)
		{
			reverse1 (&d);
		}
		else if (re == 2)
		{
			reverse2 (&d);
		}
		else
		{
			cout << "Error!";
		}
	case 13:
		cout << "\n[1]Right shift & Rotate.";
		cout << "\n[2]Left shift & Rotate.";
		cout << "\nChoose: ";
		cin >> temp;
		if (temp == 1)
		{
			rightshift_rotate (&d);
		}
		else if (temp == 2)
		{
			leftshift_rotate (&d);
		}
		else
		{
			cout << "Error!";
		}
		break;
	case 14:
		cout << "Enter the Element: ";
		cin >> Element;
		sorted_insert (&d, Element);
		break;
	case 15:
		sorted (d);
		break;
	case 16:
		rearrange (&d);
		break;
	case 17:
		Merge (&d, &d2, &d3);
		cout <<
		     "\nDo you want to perform operations on this merged array?(yes=1/No=0): ";
		cin >> temp;
		if (temp == 1)
		{
			opermenu (d3, d, d2);
		}
		break;
	case 18:
		Union (&d, &d2, &d3);
		break;
	case 19:
		intersection (&d, &d2, &d3);
		break;
	case 20:
		differance (&d, &d2, &d3);
		break;
	case 21:
		bubble_sort(&d);
		break;
	case 22:
		insertion_sort(&d);
		break;
	case 23:
		display (d);				//display operation
		break;
	default:
		cout << "No operation chosen!!";
	}

	cout << "\nDo you want to perform any other operation?(Yes=1/No=0): ";
	cin >> temp;
	if (temp == 1)
	{
		opermenu (d, d2, d3);
	}
	else
	{
		cout << "\nProgram executed!";
		delete[]d.A;
		void exit();
	}
}

int
main ()
{
	test arr;
	test arr2;
	test arr3;
	cout << "Enter the  max size of the 1st array: ";
	cin >> arr.size;				//max size of the 1st array
	arr.A = new int[arr.size];	//creation of an array in heap

	cout << "Enter the No. of elements you are going to enter :";
	cin >> arr.length;			//No. of elements present in the 1st array
	input (&arr);

	cout << "Enter the  max size of the 2nd array: ";
	cin >> arr.size;				//max size of the 2nd array
	arr2.A = new int[arr2.size];	//creation of an array in heap

	cout << "Enter the No. of elements you are going to enter :";
	cin >> arr2.length;			//No. of elements present in the 2nd array
	input (&arr2);

	opermenu (arr, arr2, arr3);
	return 0;
}