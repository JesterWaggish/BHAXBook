#include <iostream>
#include <cmath>
#include <vector>

void print(const std::vector<double>& PR){
	
    for (double value : PR)
        std::cout << value << std::endl;

}

double distance(const std::vector<double>& PR, const std::vector<double>& PRv){
	
	double sum = 0.0;
	for (int i = 0; i < PR.size(); ++i)
		sum += (PRv[i] - PR[i]) * (PRv[i] - PR[i]);
	
	return sqrt(sum);
}

int main(){

	std::vector<std::vector<double>> L = 
	{ 
	{0.0, 0.0, 1.0 / 3.0, 0.0}, 
    {1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0}, 
    {0.0, 1.0 / 2.0, 0.0, 0.0}, 
    {0.0, 0.0, 1.0 / 3.0, 0.0}
    };

    std::vector<double> PRv = { 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0 };
    std::vector<double> PR = { 0.0, 0.0, 0.0, 0.0 };

    int i, j;

    for (;;){

    	for(i = 0; i < PR.size(); ++i){

    		PR[i] = 0.0;
    		
            for(j = 0; j < PRv.size(); ++j)
    			PR[i] += (L[i][j] * PRv[j]);
    	}

		if (distance(PR, PRv) < 0.00000001)
			break;
		
        for(i = 0; i < PR.size(); ++i)
			PRv[i] = PR[i];
    	
    }

    print(PR);

    return 0;
}