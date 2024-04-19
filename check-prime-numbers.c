#include <pthread.h>
#include <stdio.h>

#define MAX_NUM 5000000

int count = 1;
pthread_mutex_t mutex;

void *verifica_primo(){
        while(1){
                pthread_mutex_lock(&mutex);
                int n = count++;
                pthread_mutex_unlock(&mutex);

                if(n == 1 ||  n > MAX_NUM){
                        break;
                }

                int primo = 1;
                for(int i=2; i*i <= n; i++){
                        if(n % i == 0){
                                primo = 0;
                                break;
                        }
                }
		if(primo == 1){
                        printf("O número é primo:  %d\n", n);
                }
        }


}

int main(){
        pthread_t t[4];
        for(int i=0; i<4; i++){
                (void) pthread_create(&t[i], NULL, verifica_primo, NULL);
        }

        for(int i=0; i<4; i++){
                (void) pthread_join(t[i], NULL);
        }

        return 0;
}

