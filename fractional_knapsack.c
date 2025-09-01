# include<stdio.h>
void knapsack(int n, float weight[], float profit[], float capacity) {
  // write your code here
  
  float ratio[20], temp;
    float x[20];   // to track fraction of each item taken
    float totalProfit = 0.0;
    int i, j;

    
    for (i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

 
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
               
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

               
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

            
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    // initialize fractions
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    // greedy fill
    float remaining = capacity;
    for (i = 0; i < n; i++) {
        if (weight[i] <= remaining) {
            x[i] = 1.0;  // take full item
            totalProfit += profit[i];
            remaining -= weight[i];
        } else {
            x[i] = remaining / weight[i]; 
            totalProfit += profit[i] * x[i];
            break;  // knapsack full
        }
    }

    printf("Maximum profit is:- %f\n", totalProfit);
}

int main() {
	float weight[20], profit[20], capacity;
	int num, i, j;
	float ratio[20], temp;
	printf("Enter the no. of objects: ");
	scanf("%d", &num);
	printf("Enter the weights and profits of each object:\n");
	for (i = 0; i < num; i++) {
		scanf("%f %f", &weight[i], &profit[i]);
	}
	printf("Enter the capacity of knapsack:");
	scanf("%f", &capacity);
	for (i = 0; i < num; i++) {
		ratio[i] = profit[i] / weight[i];
	}

	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (ratio[i] < ratio[j]) {
				temp = ratio[j];
				ratio[j] = ratio[i];
				ratio[i] = temp;
				temp = weight[j];
				weight[j] = weight[i];
				weight[i] = temp;
				temp = profit[j];
				profit[j] = profit[i];
				profit[i] = temp;
			}
		}
	}
	knapsack(num, weight, profit, capacity);
	return(0);
}
