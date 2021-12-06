#include <iostream>
#include <fstream>
#include <vector>

#define FN "input.txt"

int sliding_windows(const std::vector<int>&, std::size_t);

int main(int argc, char** argv){
	if(argc > 1){
		std::ifstream ifs(argv[1]);
		std::vector<int> depths;
		if(ifs.is_open()){
			int depth;
			while(ifs >> depth){
				depths.push_back(depth);
			}
		}
		
		int n = sliding_windows(depths, 3);
		std::cout << "Result: " << n << '\n';
		
	}else{
		std::cerr << "Missing \'" << FN << "\' file.\n";
		return 1;
	}
	
	return 0;
}

int sliding_windows(const std::vector<int>& dataset, std::size_t wsize){
	int n = 0;
	
	int wsum = 0;
	for(std::size_t i = 0; i<wsize; ++i){
		wsum += dataset[i];
	}
	
	std::vector<int> wdataset;
	wdataset.push_back(wsum);
	for(std::size_t i = wsize; i<dataset.size(); ++i){
		wsum = wsum - dataset[i-wsize] + dataset[i];
		wdataset.push_back(wsum);
	}

	char gid = 'A';
	std::cout << gid << ": " << wdataset[0] << " (N/A - no previous sum)\n";
	for(std::size_t i = 1; i<wdataset.size(); ++i){
		++gid;
		std::cout << gid << ": " << wdataset[i] << ' ';
		if(wdataset[i] > wdataset[i-1]){
			std::cout << "(increased)";
			++n;
		}else if(wdataset[i] < wdataset[i-1]){
			std::cout << "(decreased)";
		}else{
			std::cout << "(no change)";
		}
		std::cout << '\n';
		
		if(gid == 'Z'){
			gid = 'A';
		}		
	}
	
	return n;
}