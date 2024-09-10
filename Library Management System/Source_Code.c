
#include<stdio.h>
int main()
{
    printf("=========Menu========\n");
    printf("=  1.Search Book    =\n");
    printf("=  2.Display Book   =\n");
    printf("=  3.Add Book       =\n");
    printf("=  4.Exit           =\n");
    printf("=======================");

    int a1;
    printf("Enter 1: ");
    scanf("%d",&a1);

    printf("\n\n");

    if(a1==1){
        printf("Choose your Book Category: \n\n");

        printf("1. Computer Science\n");
        printf("2. Mathematics\n");
        printf("3. Data Structure\n");
        printf("4. Electronics\n");
        printf("5. Mechanical\n");
        printf("6. Physics\n");

        int a2;
        printf("Choose a Category: ");
        scanf("%d", &a2);

        printf("\n\n");

        if(a2==1){
            printf("You have choosed Computer Science.\n\n");

            printf("1.Introduction to C\n");
            printf("2. Introduction to Python\n");
            printf("3. Introduction to c++\n");
            printf("4. Introduction to Java\n");
            printf("5. Introduction to HTML & CSS\n");

            int a3;
            printf("Choose a Book: ");
            scanf("%d", &a3);

            printf("\n\n");

            if(a3==1){
                printf("You have choosed Introduction to C Book\n\n");

                char book_namea[50];
                char author_namea[50];
                int pagea;
                int pricea;

                printf("Book Name: ");
                scanf("%s", &book_namea);
                printf("\n\n");

                printf("Author Name: ");
                scanf("%s", &author_namea);
                printf("\n\n");

                printf("Pages: ");
                scanf("%s", &pagea);
                printf("\n\n");

                printf("Price: ");
                scanf("%s", &pricea);
                printf("\n\n");

            }
            else if(a3==2){
                printf("You have choosed Introduction to Python\n\n");

                char book_nameb[50];
                char author_nameb[50];
                int pageb;
                int priceb;

                printf("Book Name: ");
                scanf("%s", &book_nameb);
                printf("\n\n");

                printf("Author Name: ");
                scanf("%s", &author_nameb);
                printf("\n\n");

                printf("Pages: ");
                scanf("%s", &pageb);
                printf("\n\n");

                printf("Price: ");
                scanf("%s", &priceb);
                printf("\n\n");

            }
            else if(a3==3){
                printf("You have choosed Introduction to C++\n\n");

                char book_namec[50];
                char author_namec[50];
                int pagec;
                int pricec;

                printf("Book Name: ");
                scanf("%s", &book_namec);
                printf("\n\n");

                printf("Author Name: ");
                scanf("%s", &author_namec);
                printf("\n\n");

                printf("Pages: ");
                scanf("%s", &pagec);
                printf("\n\n");

                printf("Price: ");
                scanf("%s", &pricec);
                printf("\n\n");
            }
            else if(a3==4){
                printf("You have choosed Introduction to Java\n\n");

                char book_named[50];
                char author_named[50];
                int paged;
                int priced;

                printf("Book Name: ");
                scanf("%s", &book_named);
                printf("\n\n");

                printf("Author Name: ");
                scanf("%s", &author_named);
                printf("\n\n");

                printf("Pages: ");
                scanf("%s", &paged);
                printf("\n\n");

                printf("Price: ");
                scanf("%s", &priced);
                printf("\n\n");
            }
            else if(a3==5){
                printf("You have choosed Introduction to HTML & CSS\n\n");

                char book_namee[50];
                char author_namee[50];
                int pagee;
                int pricee;

                printf("Book Name: ");
                scanf("%s", &book_namee);
                printf("\n\n");

                printf("Author Name: ");
                scanf("%s", &author_namee);
                printf("\n\n");

                printf("Pages: ");
                scanf("%s", &pagee);
                printf("\n\n");

                printf("Price: ");
                scanf("%s", &pricee);
                printf("\n\n");
            }
        }
        else if (a2==2){
            printf("You have choosen Mathematics\n\n");

            printf("1. Mathematics I");
            printf("2. Mathematics II");
            printf("3. Discrete Mathematics III");

            int a4;
            printf("Choose a book: ");
            scanf("%d", &a4);

            printf("\n\n");

            if(a4==1){
                printf("You have choosed Mathematics I\n\n");
                
                char book_namef[50];
                char author_namef[50];
                int pagef;
                int pricef;

                printf("Book Name: ");
                scanf("%s", &book_namef);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_namef);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pagef);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &pricef);
                printf("\n\n");
            }
            else if(a4==2){
            printf("You have choosed Mathematics II\n\n");
            
                char book_nameg[50];
                char author_nameg[50];
                int pageg;
                int priceg;

                printf("Book Name: ");
                scanf("%s", &book_nameg);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_nameg);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pageg);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &priceg);
                printf("\n\n");
            }
            else if (a4==3){
                printf("You have choosed Mathematics I\n\n");
                
                char book_nameh[50];
                char author_nameh[50];
                int pageh;
                int priceh;

                printf("Book Name: ");
                scanf("%s", &book_nameh);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_nameh);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pageh);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &priceh);
                printf("\n\n");
            }
        
        }
        if (a2==3){
            printf("You have choosen Data Structure");

            printf("1. DS stack & Quene ");
            printf("2. DS Linklist");
            printf("3. DS Tree & Graph");

            int a5;
            printf("Choose a book: ");
            scanf("%d", &a5);

            printf("\n\n");

            if(a5==1){
                printf("You have choosen DS stack & Quene");
                
                char book_namei[50];
                char author_namei[50];
                int pagei;
                int pricei;

                printf("Book Name: ");
                scanf("%s", &book_namei);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_namei);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pagei);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &pricei);
                printf("\n\n");
            }
            else if(a5==2){
                printf("You have choosen DS Linklist ");

                char book_namej[50];
                char author_namej[50];
                int pagej;
                int pricej;

                printf("Book Name: ");
                scanf("%s", &book_namej);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_namej);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pagej);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &pricej);
                printf("\n\n");
            }
            else if(a5==3){
                printf("You have choosen DS Tree & Graph");

                char book_namek[50];
                char author_namek[50];
                int pagek;
                int pricek;

                printf("Book Name: ");
                scanf("%s", &book_namek);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_namek);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pagek);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &pricek);
                printf("\n\n");
            }
        }
        if(a2==4){
            printf(" You have choosen Electrical");

            printf("1. Introduction to BEE ");
            printf("2. Advance IEE & BEE  ");
            printf("3. Introduction to IEE");

            int a6;
            printf("Choose a book: ");
            scanf("%d", &a6);

            printf("\n\n");
            
            if(a6==1){
                printf("You have choosen Introduction to BEE");

                char book_namek[50];
                char author_namek[50];
                int pagek;
                int pricek;

                printf("Book Name: ");
                scanf("%s", &book_namek);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_namek);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pagek);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &pricek);
                printf("\n\n");
            }
            else if(a6==2){
                printf("You have choosen Advance IEE & BEE ");

                char book_namel[50];
                char author_namel[50];
                int pagel;
                int pricel;

                printf("Book Name: ");
                scanf("%s", &book_namel);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_namel);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pagel);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &pricel);
                printf("\n\n");
            }
            else if(a6==3){
                printf("You have choosen Introduction to IEE");

                char book_namem[50];
                char author_namem[50];
                int pagem;
                int pricem;

                printf("Book Name: ");
                scanf("%s", &book_namem);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_namem);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pagem);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &pricem);
                printf("\n\n");
            }
        }
        if(a2==5){
            printf("You have choosen Mechanical");

            printf("1. Introdcution to Mechanical Engineering ");
            printf("2. Advance Learning in ME");

            int a7;
            printf("Choose a book: ");
            scanf("%d", &a7);

            printf("\n\n");

            if(a7==1){
                printf("You have choosen Introduction to Mechanical Engineering");

                char book_namen[50];
                char author_namen[50];
                int pagen;
                int pricen;

                printf("Book Name: ");
                scanf("%s", &book_namen);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_namen);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pagen);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &pricen);
                printf("\n\n");
            }
            else if(a7==2){
                printf("You have choosen Advance Learning in ME");

                char book_nameo[50];
                char author_nameo[50];
                int pageo;
                int priceo;

                printf("Book Name: ");
                scanf("%s", &book_nameo);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_nameo);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pageo);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &priceo);
                printf("\n\n");
            }
        }
        if(a2==6){
            printf("You have choosen Physics ");

            printf("1. Introdcution to Engineering In Physics ");
            printf("2. Advance Learning in Physics");

            int a8;
            printf("Choose a book: ");
            scanf("%d", &a8);

            printf("\n\n");
            
            if(a8==1){
                printf("You have choosen Introduction to Engineering in Physics");

                char book_namep[50];
                char author_namep[50];
                int pagep;
                int pricep;

                printf("Book Name: ");
                scanf("%s", &book_namep);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_namep);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pagep);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &pricep);
                printf("\n\n");
            }
            else if(a8==2){
                printf("You have choosen Advance Learning in Physics");

                char book_nameq[50];
                char author_nameq[50];
                int pageq;
                int priceq;

                printf("Book Name: ");
                scanf("%s", &book_nameq);
                printf("\n\n");

                printf("Author name: ");
                scanf("%s", &author_nameq);
                printf("\n\n");

                printf("Page no.: ");
                scanf("%d", &pageq);
                printf("\n\n");

                printf("Price: ");
                scanf("%d", &priceq);
                printf("\n\n");
            }
        }
    }
    else if(a1==3){
        printf("You Can Search the book (Book Status)\n\n");

        printf("Press the Code:311 for Introduction in C");
        printf("Press the Code:113 for Introduction in C");
        printf("Press the Code:231 for Introduction in C");
        printf("Press the Code:789 for Introduction in C");
        printf("Press the Code:159 for Introduction in C");
        printf("Press the Code:453 for Introduction in C");
        printf("Press the Code:654 for Introduction in C");
        printf("Press the Code:963 for Introduction in C");
        printf("Press the Code:753 for Introduction in C");
        printf("Press the Code:357 for Introduction in C");
        printf("Press the Code:852 for Introduction in C");
        printf("Press the Code:256 for Introduction in C");
        printf("Press the Code:145 for Introduction in C");
        printf("Press the Code:236 for Introduction in C");
        printf("Press the Code:696 for Introduction in C");
        printf("Press the Code:955 for Introduction in C");
        
    }
}

