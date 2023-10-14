#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>
                         /***********************************************
                         *  Projet by: Loubna Sai                        *
                         *                                               *
                         *    Group TP : G4b                             *
                         *                                               *
                         *    CNE:  20-C130083903                        *
                         *************************************************/
typedef struct date{
    int jour;
    int mois;
    int annee;
}date;

typedef struct voiture{
    int idVoiture;
    char marque[15];
    char nomVoiture[15];
    char couleur[7];
    int nbplaces;
    int prixJour;
    char EnLocation[4];
}voiture;

typedef struct contraLocation{
    float numContrat;
    int idVoiture;
    int idClient;
    date debut;
    date fin;
    int cout;
}contrat;

typedef struct client{
    int idClient;
    char nom[20];
    char prenom[20];
    int cin;
    char adresse[15];
    int telephone;
}client;
//**********POUR LE MENU DE GESTION DES VOITURE*******

void GS_voiture(){//TERMINER TOU LES FONCTION
     system("cls");
    int choix;
    voiture *a=NULL;
    while(1){
        do{
            printf("\n                                                   \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
            printf("\n                                                   \xb3 Gestion des voitures \xb3");
            printf("\n                                                   \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
            printf("\n\n");
            printf("\n                                        \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
            printf("\n                                        \xba                                              \xba");
            printf("\n                                        \xba    Liste des voitures....................1   \xba");
            printf("\n                                        \xba    Ajouter voiture.......................2   \xba");
            printf("\n                                        \xba    Modifier voiture......................3   \xba");
            printf("\n                                        \xba    Supprimer voiture.....................4   \xba");
            printf("\n                                        \xba    Retour................................5   \xba");
            printf("\n                                        \xba                                              \xba");
            printf("\n                                        \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
            printf("\n\n                                                       Votre choix  :  ");

            scanf("%d",&choix);
        }while(choix<0 || choix>5);
            system("cls");
        switch(choix){
            case 1 : aff_voiture() ;
                break;
            case 2 : ajouter_voiture(&a) ;
                break;
            case 3 : modifier_voiture(&a) ;
                break;
            case 4 : supprimer_voiture(&a);
                break;
            default : main();
                break;
        }
    }
}

int comp_voiture(voiture *a,int id){//POUR TESTER EST CE QUE IL EXISTE DEJA UN ID
    FILE *ptrvoi=NULL;
    ptrvoi=fopen("liste_voiture.txt","rb");
    while(fread(a,sizeof(voiture),1,ptrvoi)==1){
        if(id==a->idVoiture){
            return 1;
        }
    }
    return 0;
}

//FONCTION D'AJOUTE UNE VOITURE
void ajouter_voiture(voiture *a){//TERMINER !!!!!
    system("cls");
    int id;
    FILE *ptrvoi=NULL;
    ptrvoi=fopen("liste_voiture.txt","ab");//ouverture d'un fichier
    if(ptrvoi==NULL){printf("Erreur d'ouverture\n"); exit(-1);}
    else{
        char answer;
        do{
            printf("      ========================================\n");
            printf("\n\t=>Donner le id de voiture: \n");
            scanf("%d",&id);
            if(comp_voiture(a,id)==1){
                system("cls");
                printf("\n\t L'ID DEJA EXISTE....VEUILLER SAISIRE UN AUTRE ID",id);
                sleep(3);
                system("cls");
                ajouter_voiture(&a);
            }
            else a->idVoiture=id;
            printf("\n\t=>Donner la marque de voiture: ");
            scanf("%s",a->marque);
            fflush(stdin);
            printf("\n\t=>Donnez le nom : ");
            scanf("%s",a->nomVoiture);
            fflush(stdin);
            printf("\n\t=>Donner la couleur de voiture: ");
            scanf("%s",a->couleur);
            fflush(stdin);
            printf("\n\t=>Donner la nbr de place de voiture: ");
            scanf("%d",&a->nbplaces);
            fflush(stdin);
            printf("\n\t=>Donner le prix de jour: ");
            scanf("%d",&a->prixJour);
            fflush(stdin);
            printf("\n\t=>Est-ce que en locatin ??");
            scanf("%s",&a->EnLocation);
            fflush(stdin);
            fwrite(a,sizeof(voiture),1,ptrvoi);
            printf("\n\t=>Voulez-vous ajouter une autre voiture(o/n)?  reponse: ");
            answer=getche();
            printf("\n");
    }while(answer=='o' || answer=='O');
    fclose(ptrvoi);
    system("cls");
}
}

//LISTE DE VOITURE
void aff_voiture(){//TERMINER !!!!!
        system("cls");
    int i=0;
    voiture a;
    FILE *ptrvoi=NULL;
    ptrvoi=fopen("liste_voiture.txt","rb");
    if(ptrvoi==NULL){printf("Erreur d'ouverture\n"); exit(-1);}
    fseek(ptrvoi,0,SEEK_SET);
    while(fread(&a,sizeof(voiture),1,ptrvoi)!=0){
        printf("\n *********Le id de la voiture : %d********",a.idVoiture);
        printf("\n La marque de la voiture ....: %s",a.marque);
        printf("\n Le nom de la voiture .......: %s",a.nomVoiture);
        printf("\n La coleur de la voiture.....: %s",a.couleur);
        printf("\n Le nembre de place..........: %d",a.nbplaces);
        printf("\n Le prix de jour.............: %d",a.prixJour);
        printf("\n Location....................: %s",a.EnLocation);
        printf("\n---------------------------------------\n");
       i++;
    }
    if(i==0){
        printf("aucun client !!!");
        sleep(3);
    }
    fseek(ptrvoi, 0, SEEK_SET);
     fclose(ptrvoi);
     system("pause");
     system("cls");
}

//POUR LA MODIFICATION
void modifier_voiture(voiture a){//TERMINER !!!!
    system("cls");
    int aide = 0;
    int id;
    char test;
    FILE *ptrvoi=NULL;
    ptrvoi=fopen("liste_voiture.txt","rb+");
    if(ptrvoi==NULL){printf("Erreur d'ouverture\n"); exit(-1);}
    else{
    printf("Donnez le id : ");
    scanf("%d",&id);
    fseek(ptrvoi, 0, SEEK_SET);
    while (fread(&a, sizeof(voiture), 1, ptrvoi) != 0 && aide==0) {
        if (a.idVoiture== id) {
            aide= 1 ;
            break ;
        }
    }

	   if (aide== 0)  {printf("Cette voiture n'existe pas\n");}

      else {
            fseek(ptrvoi,-sizeof (voiture),SEEK_CUR) ;
            printf("Les information : \n");
            printf("La marque du voiture: %s\n",a.marque  );
            printf("Le nom du voiture : %s\n",a.nomVoiture  );
            printf("La couleur du voiture : %s\n",a.couleur  );
            printf("Le nembre de place : %d\n",a.nbplaces  );
            printf("Le prix de jour : %d\n",a.prixJour  );
            printf("\n\n qu'est ce que tu veux changer ? \n ============================= \n ");

             a.idVoiture = a.idVoiture ;
             printf("\n -> Voulez-vous modifier la marque(o/n)? : \t ");//Modification de la marque
             scanf("%s",&test) ;
             if(test == 'o' || test=='O') {
                printf("Entrez la nouveau marque :");
                scanf("%s",&a.marque) ;
                fflush(stdin);
             }
             else strcpy(a.marque , a.marque) ; printf("\n");
             printf("\n -> Voulez-vous modifier le nom(o/n)? : \t ") ;//Modification de le nom
             scanf("%s",&test) ;
             if(test=='o' || test=='O') {
                printf("Entrez le nouveau nom :");
                scanf("%s",&a.nomVoiture) ;
                fflush(stdin);}
             else strcpy(a.nomVoiture,a.nomVoiture) ; printf("\n");
             printf("\n -> Voulez-vous modifier la couleur(o/n)? : \t ") ; //Modification de la coleurs
             scanf("%s",&test) ;
             if(test=='o' || test=='O') {
                    printf("Entrez la nouvelle couleur :");
                    scanf("%s",&a.couleur) ;
                    fflush(stdin);}
             else strcpy(a.couleur,a.couleur) ; printf("\n");
             printf("\n -> Voulez-vous modifier le nembre de place(o/n)? : \t ") ; //Modification de la place
             scanf("%s",&test) ;
             if(test=='o' || test=='O') {
                    printf("Entrez le nouveau nembre de place :");
                    scanf("%d",&a.nbplaces);
                    fflush(stdin); }
             else a.nbplaces = a.nbplaces ; printf("\n");
             printf("\n -> Voulez-vous modifier le prix de jour(o/n)? : \t ") ; //Modification de le prix
             scanf("%s",&test) ;
             if(test=='o' || test=='O') {
                    printf("Entrez le nouveau prix de jour :");
                    scanf("%d",&a.prixJour);
                    fflush(stdin);
             }
             else a.prixJour = a.prixJour ; printf("\n");
             fwrite(&a,sizeof (voiture),1,ptrvoi);
      }
    }
       fseek(ptrvoi, 0, SEEK_SET);
    system("cls");
}

//POUR SUPPRIMER UN VOITURE
void supprimer_voiture(voiture *a){//TERMINER !!!!
system("cls");
    int id;
    FILE *ptrvoi=NULL;
    ptrvoi=fopen("liste_voiture.txt","rb");
    if(ptrvoi==NULL){printf("Erreur d'ouverture\n"); exit(1);}
    else{
        FILE *ptrvoitemporaire=fopen("temporaire.txt","wb");
        if(ptrvoitemporaire==NULL){printf("\n\n Echec d'ouverture du fichier!!\n\n");
            exit(1);}
        else{ printf("\n\n\t\t   Entrer le id voiture a supprimee : ");
        scanf("%d",&id);
        bool id_dedecte=false;
        while(fread(a,sizeof(voiture),1,ptrvoi)==1){
            if(a->idVoiture==id){
                id_dedecte=true;
                printf("\n\n => La voiture a ete detect et supprimer avec succes.\n\n");
            }
            else fwrite(a,sizeof(voiture),1,ptrvoitemporaire);
        }
        fclose(ptrvoi);
        fclose(ptrvoitemporaire);
        if(id_dedecte==true){
            remove("liste_voiture.txt");
            rename("temporaire.txt","liste_voiture.txt");
        }
        else remove("temporaire.txt");
    }
}
sleep(2);
system("cls");
}

//*********POUR LE MUNU DE LOCATION***********
void location(){
    int choix;
    client *s=NULL;
    contrat *l=NULL;
    voiture *a=NULL;
    while(1){
        do{
            printf("\n                                                     \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
            printf("\n                                                     \xb3 Location d'une voiture \xb3");
            printf("\n                                                     \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
            printf("\n\n");
            printf("\n                                        \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
            printf("\n                                        \xba                                              \xba");
            printf("\n                                        \xba    Visualiser contrat...................1    \xba");
            printf("\n                                        \xba    Louer voiture........................2    \xba");
            printf("\n                                        \xba    Retourner voiture....................3    \xba");
            printf("\n                                        \xba    Modifier contrat.....................4    \xba");
            printf("\n                                        \xba    Supprimer contrat....................5    \xba");
            printf("\n                                        \xba    Retour...............................6    \xba");
            printf("\n                                        \xba                                              \xba");
            printf("\n                                        \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
            printf("\n\n                                                       Votre choix  :  ");

            scanf("%d",&choix);
       } while(choix<0 || choix>6);
       system("cls");
    switch(choix){
        case 1 : visualiserContrat();
            break;
        case 2 : louerVoiture(&l,&s,&a);
            break;
        case 3 : retourner(&l,&a);
            break;
        case 4 : modifierContrat(l);
            break;
        case 5 : supprimerContrat(&l);
            break;
        default : main();
            break;
    }
    }
}

void visualiserContrat(){
    contrat l;
    float num;
    int aide;
    FILE *ptrcont=NULL;
    ptrcont=fopen("contrats_locations.txt","rb");
    printf("      ========================================\n");
    while(fread(&l,sizeof(contrat),1,ptrcont)==1){
            printf("\n");

            printf("\t *******Le numero de contra : %.2f *********\n",l.numContrat);
            printf("\t L'id de voiture : %d \n",l.idVoiture);
            printf("\t L'id de client : %d \n",l.idClient);
            printf("\t La date de debut du contrat : %d / %d / %d \n",l.debut.jour,l.debut.mois,l.debut.annee);
            printf("\t La date de fin du contrat : %d / %d / %d \n",l.fin.jour,l.fin.mois,l.fin.annee);
            printf("\t Le count : %d",l.cout);
            printf("\n---------------------------------------\n");
    }
    fclose(ptrcont);
    system("pause");
    system("cls");
}

int jourcalc(int jourdeb,int moisdeb,int anneedeb,int jourend,int moisend,int anneeend){//CETTE FONCTION POUR CALCULE LES JOUR QUANT LOUER LA VOITURE
    int result,debut,fin,somme=0,i,test=jourdeb;
    int mois[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=0;i<=moisdeb-2;i++){
        somme+=mois[i];
    }
    debut=somme+test;
    somme=0;
    for(i=0;i<=moisend-2;i++){
        somme+=mois[i];
    }
    fin=somme+jourend+((anneeend-anneedeb)*365.25);
    result=fin-debut;
    return result;
}

//POUR LOUER UNE VOITURE
void louerVoiture(contrat *l,client *s,voiture *a){
    system("cls");
    FILE *ptrclient=NULL;
    FILE *ptrvoi=NULL;
    ptrvoi=fopen("liste_voiture.txt","rb+");
    FILE *ptrcont=NULL;
    ptrcont=fopen ("contrats_locations.txt", "ab");
    int conteur1=0,conteur2=0;
    char nm[20],pr[20];
    printf("      ========================================\n");
    printf("\t Votre nom s'il vous plait :");
    scanf("%s",nm);
    printf("\n \t Votre prenom s'il vous plait :");
    scanf("%s",pr);
    ptrclient=fopen("liste_client.txt","rb");
    while(fread(s,sizeof(client),1,ptrclient)==1){
        if(strcmp(s->nom,nm)==0 && strcmp(s->prenom,pr)==0){
            conteur1=1;
            break;
        }
    }
    system("cls");
    if(conteur1==1){
        char nomVoiture[15],marque[15],couleur[7];
        int nbplaces;
        printf("      ========================================\n");
        printf("\n\t==>Entrez les information de voiture volue : \n");
        printf("\n\t* La marque : " );
        scanf("%s",marque);
        fflush(stdin);
        printf("\n\t* Le nom de voiture : ");
        scanf("%s",nomVoiture);
        fflush(stdin);
        printf("\n\t* La couleur : ");
        scanf("%s",couleur);
        fflush(stdin);
        printf("\n\t* le nembre de place : ");
        scanf("%d",&nbplaces);
        while(fread(a,sizeof(voiture),1,ptrvoi)==1){
            if(strcmp(a->marque,marque)==0 && strcmp(a->nomVoiture,nomVoiture)==0 && strcmp(a->couleur,couleur)==0 && a->nbplaces==nbplaces)
            {
                conteur2=1;
                break;
            }
        }
        if(conteur2==1){
            if(strcmp(a->EnLocation, "non") == 0){
                strcpy(a->EnLocation , "oui");
                printf("Cette voiture est disponible .... ");
                printf("\n Numero de votre contrat : ");
                scanf("%f",&l->numContrat);
                l->idVoiture=a->idVoiture ;
                fseek(ptrclient,0,SEEK_SET);
                while(fread(s,sizeof(client),1,ptrclient)==1){
                    if(strcmp(s->nom,nm)==0 && strcmp(s->prenom,pr)==0){
                        break;
                    }
                }
                l->idClient=s->idClient ;
                printf("\n Tu vas prendre la voiture quand ? : ");

                scanf("%d %d %d" ,&l->debut.jour,&l->debut.mois,&l->debut.annee);
                printf("\n Jusqu'a :");
                scanf("%d %d %d" ,&l->fin.jour,&l->fin.mois,&l->fin.annee);
                l->cout=jourcalc(l->debut.jour,l->debut.mois,l->debut.annee,l->fin.jour,l->fin.mois,l->fin.annee)*conteur2 ;
                fwrite (l,sizeof(contrat),1,ptrcont);
            }
        }
        else {
            printf("cette voiture n'est pas valable  \n");
        }
    }

    else{
        printf("Ce nom n'existe pas!!!!!\n");
        printf("vous voulez engregister vos information \n");
        sleep(3);
        system("cls");
        GS_client();
    }
    fseek(ptrvoi, 0, SEEK_SET); fseek(ptrcont, 0, SEEK_SET); fseek(ptrclient, 0, SEEK_SET);
    fclose(ptrclient);fclose(ptrcont);fclose(ptrvoi);
    system("cls");
}

 //POUR RETOURNER UNE VOITURE
void retourner(contrat *l,voiture *a){
    int aide;
    float num;
    FILE *ptrvoi=NULL;
    ptrvoi=fopen("liste_voiture.txt","rb+");
    FILE *ptrcont=NULL;
    ptrcont=fopen ("contrats_locations.txt", "rb");
    printf("Entrez le numero de contrat :\n");
    scanf("%f",&num);
    while(fread(l,sizeof(contrat),1,ptrcont)==1){
        if(l->numContrat==num){
            aide=1;
            break;
        }
    }
    if(aide==1){
        float num;
        FILE *ptrcont=NULL;
        ptrcont=fopen("contrats_locations.txt","rb");
        FILE *ptrcontemporaire=fopen("Cntemporaire.txt","wb");
        bool num_dedecte=false;
        while(fread(l,sizeof(contrat),1,ptrcont)==1){
            if(l->numContrat==num){
                num_dedecte=true;
            }
            else {fwrite(l,sizeof(contrat),1,ptrcontemporaire);}
        }
        fclose(ptrcont);
        fclose(ptrcontemporaire);
        if(num_dedecte==true){
            remove("contrats_locations.txt");
            rename("Cntemporaire.txt","contrats_locations.txt");
        }
        else remove("Cntemporaire.txt");
        strcpy(a->EnLocation,"non");
    }
    else printf("\n\t Ce numero n'existe pas !!!!!");
    fclose(ptrcont);fclose(ptrvoi);
    system("cls");
}

//POUR MOUDIFIER UN CONTRAT
void modifierContrat(contrat l){
    FILE *ptrcont=NULL;
    ptrcont=fopen("contrat_location.txt","rb+");
    if(ptrcont==NULL){printf("Erreur d'ouverture\n"); exit(-1);}
    int aide=0;
    float num;
    char test;
    printf("Entrez le numero de contrat que vous voulez modifier : ");
    scanf("%f",&num);
    fseek(ptrcont, 0, SEEK_SET);
    while(fread(&l,sizeof(contrat),1,ptrcont)==1){
        if(l.numContrat==num){
            aide=1;
            break;
        }
    }
    if(aide==0) printf("Ce contrat n'existe pas\n");
    else {
        fseek(ptrcont,-sizeof(contrat),SEEK_CUR);
        printf("***Les information : \n");
        printf("\tLa date de debut ........ ........: %d /%d /%d\n",l.debut.jour,l.debut.mois,l.debut.annee);
        printf("\tLa date de fin .............: %d /%d /%d\n",l.fin.jour,l.fin.mois,l.fin.annee);
        printf("\n\n qu'est ce que tu veux changer ? \n ============================= \n ");
        l.numContrat =l.numContrat;
        printf("\n -> Voulez-vous modifier le debut de date (o/n)? : \t ");
        scanf("%c",&test) ;
        if(test == 'o' || test=='O'){
            printf("\n Entrez le nouveau debut de date (jj/mm/aa) :");
            scanf("%d",&l.debut.jour);printf("/");
            scanf("%d",&l.debut.mois);printf("/");
            scanf("%d",&l.debut.annee);printf("/");
        }
        else{
            l.debut=l.debut;
        }
        printf("\n -> Voulez-vous modifier la fin de date (o/n)? : \t ");
        scanf("%c",&test);
        if(test == 'o' || test=='O'){
            printf("\n Entrez la nouvelle fin de date (jj/mm/aa) :");
            scanf("%d",&l.fin.jour);printf("/");
            scanf("%d",&l.fin.mois);printf("/");
            scanf("%d",&l.fin.annee);printf("/");
        }
    }
}

//POUR SUPPRIMER UN CONTRAT
void supprimerContrat(contrat *l){//TERMINER!!!
    system("cls");
    float num;
    FILE *ptrcont=NULL;
    ptrcont=fopen("contrats_locations.txt","rb");
    if(ptrcont==NULL){printf("Erreur d'ouverture\n"); exit(-1);}
    else{
        FILE *ptrcontemporaire=fopen("Cntemporaire.txt","wb");//ouvrire un fichier temporaire
        if(ptrcontemporaire==NULL){printf("\n\n Echec d'ouverture du fichier!!\n\n");
            exit(1);}
        else{
            printf("      ========================================\n");
            printf("\n\n\t\t   Entrer le numero de contrat a supprimee : ");
            scanf("%f",&num);
            bool num_dedecte=false;
            while(fread(l,sizeof(contrat),1,ptrcont)==1){
                if(l->numContrat==num){
                    num_dedecte=true;
                    printf("\n\n => Le contrat a ete detect et supprimer avec succes.\n\n");
                }
                else {fwrite(l,sizeof(contrat),1,ptrcontemporaire);}
        }
            fclose(ptrcont);
            fclose(ptrcontemporaire);
            if(num_dedecte==true){
                remove("contrats_locations.txt");
                rename("Cntemporaire.txt","contrats_locations.txt");
        }
            else remove("Cntemporaire.txt");
    }
}
    sleep(2);
    system("cls");
}

//*********POUR LE MENU DE CLIEN*********
void GS_client(){//TERMINER TOUS LES FONCTION
    int choix;
    client *s=NULL;
    while(1){
        do{
            printf("\n                                                     \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
            printf("\n                                                     \xb3 Gestion des clients \xb3");
            printf("\n                                                     \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
            printf("\n\n");
            printf("\n                                        \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
            printf("\n                                        \xba                                              \xba");
            printf("\n                                        \xba    Liste des client......................1   \xba");
            printf("\n                                        \xba    Ajouter client........................2   \xba");
            printf("\n                                        \xba    Modifier client.......................3   \xba");
            printf("\n                                        \xba    Supprimer client......................4   \xba");
            printf("\n                                        \xba    Retour................................5   \xba");
            printf("\n                                        \xba                                              \xba");
            printf("\n                                        \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
            printf("\n\n                                                       Votre choix  :  ");

            scanf("%d",&choix);
       } while(choix<0 || choix>5);
       system("cls");
    switch(choix){
        case 1 : aff_client();
            break;
        case 2 : ajoute_client(&s);
            break;
        case 3 : modif_client(&s);
            break;
        case 4 : supr_client(&s);
            break;
        default : main();
            break;
    }
    }
}

int comp_client(client *s,int id){//POUR TESTER EST CE QUE IL EXISTE DEJA UN ID
    FILE *ptrclient=NULL;
    ptrclient=fopen("liste_client.txt","rb");
    while(fread(s,sizeof(client),1,ptrclient)==1){
        if(id==s->idClient){
            return 1;
        }
    }
    return 0;
}

//FONCTION POUR AJOUTER UN CLIENT
void ajoute_client(client *s){//TERMINER!!!!
    system("cls");
    int id;
    FILE *ptrclient=NULL;
    ptrclient=fopen("liste_client.txt","ab");//ouverture d'un fichier on mode d'ajoute
    if(ptrclient==NULL){printf("Erreur d'ouverture\n"); exit(-1);}
    else{
        char answer;
        do{
            printf("      ========================================\n");
            printf("\n\t=>Donner le id de client: \n");
            scanf("%d",&id);
            if(comp_client(s,id)==1){
                system("cls");
                printf("\n\t L'ID DEJA EXISTE....VEUILLER SAISIRE UN AUTRE ID",id);
                sleep(3);
                system("cls");
                ajoute_client(&s);
            }
            s->idClient=id;
            printf("\n\t=>Donner le nom de client: \n");
            scanf("%s",s->nom);
            fflush(stdin);
            printf("\n\t=>Donnez le prenom de client : \n");
            scanf("%s",s->prenom);
            fflush(stdin);
            printf("\n\t=>Donner le CIN de client: \n");
            scanf("%d",&s->cin);
            fflush(stdin);
            printf("\n\t=>Donner l'adresse de client: \n");
            gets(s->adresse);
            fflush(stdin);
            printf("\n\t=>Donner le telephone de client: \n");
            scanf("%d",&s->telephone);
            fflush(stdin);
            fwrite(s,sizeof(client),1,ptrclient);
            printf("\n\n");
            printf("\n\tVoulez-vous ajouter un autre client(o/n)?  reponse: ");
            answer=getchar();
            printf("\n");
            system("cls");
    }while(answer=='o' || answer=='O');
    fclose(ptrclient);
    system("cls");
}
}

//LISTE DE CLIENT
void aff_client(){//TERMINER !!!!!
    system("cls");
    int i=0;
    client s;
    FILE *ptrclient=NULL;
    ptrclient=fopen("liste_client.txt","rb");
    if(ptrclient==NULL){printf("Erreur d'ouverture\n"); exit(-1);}
    while(fread(&s,sizeof(client),1,ptrclient)==1){
        printf("\n *********Le id de le client:%d********",s.idClient);
        printf("\n Le nom de client........: %s",s.nom);
        printf("\n Le prenom de client.....: %s",s.prenom);
        printf("\n Le CIN de client........: %d",s.cin);
        printf("\n L'adresse de client.....: ");puts(s.adresse);
        printf("\n Le telephonr de client..: %d",s.telephone);
        printf("\n---------------------------------------\n");
        i++;
    }
    if(i==0){
        printf("aucun client !!!");
        sleep(3);
    }
     fclose(ptrclient);
     system("pause");
     system("cls");
}

//MODIFIER UN CLIENT
void modif_client(client s){//TERMINER !!!!!!
    system("cls");
    int aide = 0;
    int id;
    char test;
    FILE *ptrclient=NULL;
    ptrclient=fopen("liste_client.txt","rb+");
    if(ptrclient==NULL){printf("Erreur d'ouverture\n"); exit(-1);}
    else{
    printf("Donnez le id : ");
    scanf("%d",&id);
    fflush(stdin);
    fseek(ptrclient, 0, SEEK_SET);
    while (fread(&s, sizeof(client), 1, ptrclient) != 0 && aide==0) {
        if (s.idClient== id) {
            aide= 1 ;
            break ;
        }
    }

	   if (aide== 0)  {printf("Ce client n'existe pas\n");}

      else {
            fseek(ptrclient,-sizeof (client),SEEK_CUR) ;
            printf("Les information : \n");
            printf("Le nom de client : %s\n",s.nom);
            printf("Le prenom de client : %s\n",s.prenom);
            printf("CIN : %d\n",s.cin);
            printf("Adresse de client : %s\n",s.adresse);
            printf("Telephone : %d\n",s.telephone);
            printf("\n\n qu'est ce que tu veux changer ? \n ============================= \n ");

             s.idClient = s.idClient;
             printf("\n -> Voulez-vous modifier le nom (o/n)? : \t ");//Modification du nom
             scanf("%c",&test) ;
             fflush(stdin);
             if(test == 'o' || test=='O') {
                printf("Entrez le nom :");
                scanf("%s",&s.nom) ;
                fflush(stdin);
             }
             else strcpy(s.nom , s.nom) ; printf("\n");
             printf("\n -> Voulez-vous modifier le  prenom(o/n)? : \t ") ;//Modification de le prenom
             scanf("%c",&test) ;
             fflush(stdin);
             if(test=='o' || test=='O') {
                printf("Entrez le prenom:");
                scanf("%s",&s.prenom) ;
                fflush(stdin);}
             else strcpy(s.prenom,s.prenom) ; printf("\n");
             printf("\n -> Voulez-vous modifier CIN(o/n)? : \t ") ; //Modification du CIN
             scanf("%c",&test) ;
             fflush(stdin);
             if(test=='o' || test=='O') {
                    printf("Entrez CIN :");
                    scanf("%d",&s.cin) ;
                    fflush(stdin);}
             else s.cin=s.cin ; printf("\n");
             fflush(stdin);
             printf("\n -> Voulez-vous modifier l'adresse(o/n)? : \t ") ; //Modification de l'adresse
             scanf("%c",&test) ;
             fflush(stdin);
             if(test=='o' || test=='O') {
                    printf("Entrez l'adresse :");
                    scanf("%s",&s.adresse);
                    fflush(stdin); }
             else strcpy(s.adresse , s.adresse) ; printf("\n");
             printf("\n -> Voulez-vous modifier le Telephone(o/n)? : \t ") ; //Modification du telephone
             scanf("%c",&test) ;
             if(test=='o' || test=='O') {
                    printf("Entrez l'adresse :");
                    scanf("%d",&s.telephone);
                    fflush(stdin); }
             else s.telephone = s.telephone ; printf("\n");
             fwrite(&s,sizeof (client),1,ptrclient);
      }
    }
       fseek(ptrclient, 0, SEEK_SET);
    system("cls");
}

//SUPPRIMER UN CLIENT
void supr_client(client *s){//TERMINER !!!!
    system("cls");
    int id;
    FILE *ptrclient=NULL;
    ptrclient=fopen("liste_client.txt","rb");
    if(ptrclient==NULL){printf("Erreur d'ouverture\n"); exit(1);}
    else{
        FILE *ptrclintemporaire=fopen("Ctemporaire.txt","wb");//ouvrire un fichier temporaire
        if(ptrclintemporaire==NULL){printf("\n\n Echec d'ouverture du fichier!!\n\n");
            exit(1);}
        else{
            printf("      ========================================\n");
            printf("\n\n\t\t   Entrer l'id de client tu veux supprimee : ");
            scanf("%d",&id);
            bool id_dedecte=false;
            while(fread(s,sizeof(client),1,ptrclient)==1){
                if(s->idClient==id){
                    id_dedecte=true;
                    printf("\n\n => Le client a ete detect et supprimer avec succes.\n\n");
                }
                else fwrite(s,sizeof(client),1,ptrclintemporaire);
        }
            fclose(ptrclient);
            fclose(ptrclintemporaire);
            if(id_dedecte==true){
                remove("liste_client.txt");
                rename("Ctemporaire.txt","liste_client.txt");
        }
            else remove("Ctemporaire.txt");
    }
}
    sleep(2);
    system("cls");
}

// *********MAIN PRINCIPALE********
int main(){
    system("cls");
    int l;
    while(1){
        do{
            printf("\n                                                     \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
            printf("\n                                                     \xb3   Menu Principale   \xb3");
            printf("\n                                                     \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
            printf("\n\n");
            printf("\n                                        \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
            printf("\n                                        \xba                                              \xba");
            printf("\n                                        \xba    location................................1 \xba");
            printf("\n                                        \xba    Gestion voitures........................2 \xba");
            printf("\n                                        \xba    Gestion client..........................3 \xba");
            printf("\n                                        \xba    Quitter.................................4 \xba");
            printf("\n                                        \xba                                              \xba");
            printf("\n                                        \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
            printf("\n\n                                                       Votre choix  :  ");
            scanf("%d",&l);

            system("cls");
        }while(l<0 || l>4);
        switch(l){
            case 1 : location() ;
                    break;
            case 2 : GS_voiture() ;
                    break;
            case 3 : GS_client() ;
                    break;
            default : printf("\n\n \t La fin de program \t Merci !!!");
                    printf("\n\n"); printf("      ========================================\n");
                    exit(0) ;
                    break;
        }
    }
}
