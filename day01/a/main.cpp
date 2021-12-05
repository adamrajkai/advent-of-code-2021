#include <iostream>
#include <fstream>

int main(int argc, char** argv){
	if(argc > 1){
		std::ifstream ifs(argv[1]);
		int n = 0;
		if(ifs.is_open()){
			int depth, depth_old;
			ifs >> depth_old;
			std::cout << depth_old << " (N/A - no previous measurement)\n";
			while(ifs >> depth){
				std::cout << depth;
				if(depth > depth_old){
					++n;
					std::cout << " (increased)\n";
				}else{
					std::cout << " (decreased)\n";
				}
				depth_old = depth;
			}
		}
		std::cout << "All decreased: " << n << '\n';
	}

	
	return 0;
}