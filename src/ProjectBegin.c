#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846
float sum_array(float a[], int num_elements);
float * up_sampling(float a[], int uprate);

int main(void){
// erf is to be added REMEMBER!!
 	//int data[8] = {1,1,1,1,1,1,1,1}; // data
 	float Tb = 1.0; //bit duration
 	float BT = 0.3; // BT product of the filter
 	int sps = 25; // samples per symbols
 	float Ts = Tb/sps ; //sample period
 	float t[105];
 	float alpha = 2*M_PI*BT/(sqrt(log(2)));
 	float gauss[105];
 	float init = -2*Tb;
 	int i = 0;
	//printf("data[3]: %d,\nTb: %f,\nBT: %f,\nsps: %d,",data[3],Tb,BT,sps);
	//printf("Ts: %f,\ninit: %f,\ni: %d,",Ts,init,i);
	//printf("\nThe T's are here %f\n\n",2*Tb);
 	while (init < 2*Tb){
 		t[i] = (-2*Tb) + (i*Ts);
 		//printf("\n%f,  ",t[i]);
 		init = t[i];
 		i = i+1;
 		//printf("%d,  ",i);
  	}

 	for(int j=0;j<i;j++){
 		gauss[j] =  (alpha * (2 * t[j] - 0.5))-(alpha*(2*t[j]+0.5));

 	}
 	float K = M_PI/(2*sum_array(gauss,i-1));
 	for(int j=0;j<i;j++){
 		gauss[j] = K*gauss[j];
 		printf("\nGauss[%d] = %f",j,gauss[j]);
 	}
 	float nrz_data[] = {-1,1,-1,1,1,-1,1,-1};
 	float nrz = up_sampling(nrz_data,sps);


	return 0;
}

float* up_sampling(float a[],int size, int uprate){
	float new_data[size*uprate];
	int k=0;
	for(i=0;i<size;i++){
		for(j=0;j<uprate;j++){
			if(j==0){
				new_data[k] = a[i];
				k = k+1;
			}
			else{
		        new_data(k) = 0;
		        k = k+1;
			}
		}
	}
	return new_data;
}





float sum_array(float a[], int num_elements)
{
   int i, sum=0;
   for (i=0; i<num_elements; i++)
   {
	 sum = sum + a[i];
   }
   return(sum);
}
