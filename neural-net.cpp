#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

#include <training/data.hpp>
#include <Net.cpp>

void showVectorVals(string label, vector<double> &v)
{
	cout << label << " ";
	for(unsigned i = 0; i < v.size(); ++i)
	{
		cout << (double)v[i] << " ";
	}
	cout << endl;
}

void showVectorValsInt(string label, vector<double> &v)
{
	cout << label << " ";
	for(unsigned i = 0; i < v.size(); ++i)
	{
		cout << (unsigned)v[i] << " ";
	}
	cout << endl;
}

int main ()
{
	TrainingData trainData ("trainingData.txt");
	//e.g., {3, 2, 1}
	vector <unsigned> topology;
	//topology.push_back(3);
	//topology.push_back(2);
	//topology.push_back(1);

	trainData.getTopology (topology);
	Net myNet (topology);

	vector <double> inputVals, targetVals, resultVals;
	int trainingPass = 0;
	while(!trainData.isEof ())
	{
		++trainingPass;
		cout << endl << "Pass" << trainingPass << ":" << endl;
		trainData.getNextInputs (inputVals); 
		cout << inputVals.size () << ": ";
		for (auto& x : inputVals)
			cout << x << " ";
		cout << endl;
		// Get new input data and feed it forward:
		if(inputVals.size () != topology [0])
			break;
		showVectorValsInt (": Inputs :", inputVals);
		myNet.feedForward (inputVals);

		// Collect the net's actual results:
		myNet.getResults (resultVals);
		showVectorVals ("Outputs:", resultVals);

		// Train the net what the outputs should have been:
		trainData.getTargetOutputs (targetVals);
		showVectorVals ("Targets:", targetVals);
		assert (targetVals.size () == topology.back ());

		myNet.backProp (targetVals);

		// Report how well the training is working, average over recnet
		cout << "Net recent average error: "
		     << myNet.getRecentAverageError () << endl;
	}

	cout << endl << "Done" << endl;

}
