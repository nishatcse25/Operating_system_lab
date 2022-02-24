// C# program to demonstrate
// FCFS Disk Scheduling algorithm
using System;

class GFG
{
static int size = 8;

static void FCFS(int []arr, int head)
{
	int seek_count = 0;
	int distance, cur_track;

	for (int i = 0; i < size; i++)
	{
		cur_track = arr[i];

		// calculate absolute distance
		distance = Math.Abs(cur_track - head);

		// increase the total count
		seek_count += distance;

		// accessed track is now new head
		head = cur_track;
	}

	Console.WriteLine("Total number of " +
					"seek operations = " +
							seek_count);

	// Seek sequence would be the same
	// as request array sequence
	Console.WriteLine("Seek Sequence is");

	for (int i = 0; i < size; i++)
	{
		Console.WriteLine(arr[i]);
	}
}

// Driver code
public static void Main(String[] args)
{
	// request array
	int []arr = { 176, 79, 34, 60,
				92, 11, 41, 114 };
	int head = 50;

	FCFS(arr, head);
}
}

// This code is contributed by PrinciRaj1992

