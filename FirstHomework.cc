#include <iostream>
#include <vector>

// struct for heap sort algorithm
struct Data
{
	Data(std::string n, int s, int e, int sev) :
		name(n), start(s), end(e), severity(sev) {}
	Data() :
		name(std::string()), start(0), end(0), severity(0) {}
	// name of event
	std::string name;
	// start of event
	int start;
	// end of event
	int end;
	// severity of this action
	int severity;
};

class Sorter {
private:
	std::vector<Data> elements;
public:
	Sorter(std::vector<Data> data)
	{
		elements = data;
		heapSort();
		// PrintData();
	}

	std::vector<Data> GetData() { return elements; }
private:
	// prints elements, used only for debuging
	void PrintData()
	{
		for (const auto& item : elements) {
			std::cout << "Name: " << item.name << ", Numbers: " << item.start << " " << item.end << " " << item.severity << std::endl;
		}
		std::cout << "\n\n";
	}

	void heapify(int N, int i)
	{
		// Initialize largest as root
		int largest = i;

		// left = 2*i + 1
		int l = 2 * i + 1;

		// right = 2*i + 2
		int r = 2 * i + 2;

		// If left child is larger than root
		if (l < N && elements[l].severity < elements[largest].severity)
			largest = l;

		// If right child is larger than largest
		// so far
		if (r < N && elements[r].severity < elements[largest].severity)
			largest = r;

		// If largest is not root
		if (largest != i) {
			std::swap(elements[i], elements[largest]);
			// Recursively heapify the affected
			// sub-tree
			heapify(N, largest);
		}
	}

	// sorts elements by severity highest is first
	void heapSort()
	{
		int N = static_cast<int>(elements.size());
		// Build heap (rearrange array)
		for (int i = N / 2 - 1; i >= 0; i--)
			heapify(N, i);

		// One by one extract an element
		// from heap
		for (int i = N - 1; i > 0; i--) {

			// Move current root to end
			std::swap(elements[0], elements[i]);

			// call max heapify on the reduced heap
			heapify(i, 0);
		}
	}
};


int main()
{
	int n; // Number of lines
	std::cin >> n;
	std::vector<Data> dataList(n);
	int max = 0;

	for (int i = 0; i < n; ++i) {
		Data d;
		std::cin >> d.name >> d.start >> d.end >> d.severity;
		if (d.end > max)
		{
			max = d.end;
		}
		dataList[i] =  d;
	}

	Sorter* sorter = new Sorter(dataList);
	std::vector<Data> sorted = sorter->GetData();
	delete sorter;

	// array of all posible days, 0 by default
	max += 1;
	std::vector<int> days(max, 0);
	for (int i = 0; i < max; i++)
	{
		days[i] = 0;
	}

	// loop throught all actions from highrest severity to lowest
	for (int i = 0; i < sorted.size(); i++)
	{
		Data d = sorted[i];
		// loop over posible days
		for (int j = d.start; j <= d.end; j++)
		{
			if (days[j] != 0) continue;
			// change index of day only if there wasnt more important action
			days[j] = i + 1; // +1 because first element in array is 0 
		}
	}

	int index = days[0];
	int start = 0;

	for (int i = 0; i < max; i++)
	{
		if (index != days[i])
		{
			start = start == 0 ? 0 : start - 1;
			if (index == 0)
			{
				// posible that nothing happend at fist day
				// nic
				std::cout << "nic" << " " << start << " " << i - 1 << "\n";
			}
			else
			{
				// index - 1 -> when asigning days index of action was incremented
				std::cout << sorted[index - 1].name << " " << start << " " << i - 1 << "\n";
			}
			index = days[i];
			start = i + 1;
		}
	}
	// because at end index doesnt change
	std::cout << sorted[index - 1].name << " " << start - 1 << " " << max - 1 << "\n";
}

