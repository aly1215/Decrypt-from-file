//Alyssa Mae C. Olano
//BSCS 3A

#include<stdio.h>


long long int diffie(int G1,int key,int mod) //a is generator,b is private key,n is mod
{
long long int t;
if(key==1)
  return G1;
t=diffie(G1,key/2,mod);
 if(key%2==0)
  return (t*t)%mod;
 else
  return (((t*t)%mod)*G1)%mod;
}



int main()
{
 char enc;   //var where encrypted message are stored
 int p,g,a,key2,b;
 int key1 = 20;          //key1 is the programmed Private key
 //p is prime number
 //g is the generator
 //key2 is secret key of bob(sample)
 //Variable  A is the answer that to be send to bob
 //Variable B is YOUR answer that to be send to alice

    printf("============================================================================\n");
    printf("Generate Secret Key using DIFFIE HELLMAN KEY EXCHANGE and Use the Secret Key to Encrypt and decrypt the characters in the textfile\n");
    printf("============================================================================\n\n");
    // both the persons will be agreed upon the common n and g
    printf("PUBLIC KEY\n");
    printf("Enter the value of prime number: ");
    scanf("%d",&p);
    printf("Enter the value of the generator: ");
    scanf("%d",&g);


    // You wll choose your  private key
    printf("\nPLEASE ENTER YOUR PRIVATE KEY: ");
    scanf("%d",&key2);
    b = diffie(g,key2,p);

    //computing for the secret key of both person
    int secretkey1 = diffie(b,key1,p);


    printf("\n\nThe secretcode is: %d\n\n", secretkey1);

    /* open the file*/
    FILE * writefile;
    writefile = fopen ("encrypted.txt","w");
    FILE *readfile;
    readfile = fopen("decrypted.txt", "r");




                                                    char go;
    if (readfile == NULL)
    {
        printf("File is not available \n");
    }
    else
    {

        int num;


    printf("======================\n");
    printf("Enter 1 for encrypting\n");
    printf("Enter 2 for decrypting\n");
    printf("======================\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &num);


switch(num){                                                            //switch

    case 1:

        fprintf(writefile,"The Encrypted Message is: \n");
        printf("The Encrypted Message is: \n");

        char getch;
        while((getch = fgetc(readfile)) != EOF){
        int ans= (getch ^ secretkey1);
            enc = ans;
            printf("%c", enc);
            fprintf (writefile, "%c",enc); //write to textfile

       }
    break;

    case 2:
        printf("\nThe decrypted message is: \n");

        while((go = fgetc(readfile)) != EOF){
               int ans = (go ^ secretkey1);
                    enc = ans;
                    int tama = enc;
                    int duh = (tama^secretkey1);
                    char talaga = duh;
                    printf("%c", talaga);

                    fprintf(writefile,"%c\n",talaga);
        }
    break;

    default:
                    printf("Invalid Number");
}


    printf("\n\n");
    }

    /* close the file*/
    fclose (writefile);
    fclose(readfile);

 return 0;
}


