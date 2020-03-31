#include <iostream>
#include <fstream>
#include <cstdlib>
#include "todolist.h"

//fonctions de la classe task//

void task :: change_title(){
    std::cout<<"Nouveau titre:";
    std::string nouveautitre="";
    std::cin>>nouveautitre;
    title = nouveautitre;
}

void task :: change_description(){
    std::cout<<"Nouvelle description:";
    std::string nouvelledescription="";
    std::cin>>nouvelledescription;
    description=nouvelledescription;
}

void task :: change_comment(){
    std::cout<<"Nouveau commentaire:";
    std::string nouveaucommentary="";
    std::cin>>nouveaucommentary;
    comment=nouveaucommentary;
}

void task :: change_percent(){
    std::cout<<"Nouveau pourcentage(entre 0 et 100):";//je voudrais rajouter une erreur si le nb donné n'est pas compris entre 0 et 100
    std::string nouveaupourcent;
    std::cin>>nouveaupourcent;
    percent=nouveaupourcent;
}

void task :: change_priority(){
    std::cout<<"0.Priorité faible  1.Prioritaire  2.moyen"<<std::endl;
    int choix_priorite=0;
    std::cin>>choix_priorite;
    if(choix_priorite==0){priority="faible";}
    else if(choix_priorite==1){priority="prioritaire";}
    else if(choix_priorite==2){priority="moyen";}
    else{std::cout<<"Ce choix n'existe pas. Try again ;)"<<std::endl; 
        change_priority();}    
}

void task::change_creation_date(){
    std::cout<<"Nouvelle date de début:";
    std::string new_creation_date;
    std::cin>>new_creation_date;
    creation_date=new_creation_date;
}
void task::change_end_date(){
    std::cout<<"Nouvelle date de cloture:";
    std::string new_end_date;
    std::cin>>new_end_date;
    end_date=new_end_date;
}

void task::add_subtask(){//On ne va demander qu'un identifiant, un titre, un pourcentage, une date de début et une date de cloture pour les sous-taches afin d'avoir un coode plus lisible, mais on pourrait très bien tout mettre
    std::cout<<"Ajout de sous tache"<<std::endl;
    std::string id;
    std::string title;
    std::string pourcent;
    std::string date_cloture;
    std::string date_debut;
    std::cout<<""<<std::endl;
    std::cout<<"Titre de la sous-tache:";
    std::cin>>title;
    std::cout<<""<<std::endl;
    std::cout<<"Pourcentage de la sous-tache:";
    std::cin>>pourcent;
    std::cout<<""<<std::endl;
    std::cout<<"Date de debut de la sous-tache:";
    std::cin>>date_debut;
    std::cout<<""<<std::endl;
    std::cout<<"Date de cloture de la sous-tache:";
    std::cin>>date_cloture;
    std::cout<<""<<std::endl;
    task* new_subtask=new task(0,title," ",date_debut,date_cloture," ",pourcent," "," ");
    vect_sub_task.push_back(new_subtask);
    std::cout<<"Sous tache ajoutee"<<std::endl;
}

void task::print_sub_task(task* sub_task){
    std::cout<<sub_task->identifiant<<", "<<sub_task->title<<", "<<sub_task->percent<<"%, "<<sub_task->creation_date<<sub_task->end_date<<std::endl;
}

void task::print_title(){ // utilisé uniquement pour la fonction print_list_task
    std::cout<<"Titre : "<<title<<std::endl;
}

void task::print(){
    std::cout<<"Identifiant : "<<identifiant<<std::endl;
    std::cout<<"Titre : "<<title<<std::endl;
    std::cout<<"Description : "<<description<<std::endl; 
    std::cout<<"Status : "<<status<<std::endl; 
    std::cout<<"Priorité : "<<priority<<std::endl; 
    std::cout<<"Commentaire : "<<comment<<std::endl; 
    std::cout<<"Pourcentage : "<<percent<<"%"<<std::endl;
    std::cout<<"Date de début :"<<creation_date<<std::endl;
    std::cout<<"Date de cloture :"<<end_date<<std::endl;
    std::cout<<"Liste sous-taches : "<<std::endl;  
    for(auto e :vect_sub_task){
        print_sub_task(e);
        std::cout<<""<<std::endl;
        };

}

void task :: close_task(){ 
     status="fermée";
}
void task :: begin_task(){
    status="ouverte";
}

//fonctions relatives à task body//

void task_body::delete_sub_task(int n){
        task* selected_task=vect_task[n];
        std::cout<<"Supression de sous-tache"<<std::endl;
        std::cout<<"Sous-taches à effacer"<<std::endl;
        std::cout<<"Taper le numéro de la sous-tâche à effacer"<<std::endl;
        std::cout<<"0 : Annuler"<<std::endl;
        int i=1;
        for(auto a:selected_task->vect_sub_task){
            std::cout<<i;
            selected_task->print_sub_task(a);
            i++;
        }
        int choix=0;
        std::cin>>choix;
        if(choix==0){modify_task(n);}
        else if(choix!=0 && choix<selected_task->vect_sub_task.size()){
            selected_task->vect_sub_task.erase(selected_task->vect_sub_task.begin()+i-1);
        }
        else{std::cout<<"Ce choix est impossible. Try again"<<std::endl;
        delete_sub_task(n);
        }

}

void task_body::modify_task(int n){
    task* selected_task=vect_task[n];
    std::cout<<"Modifier une tâche"<<std::endl;
    std::cout<<"0.Retour "<<std::endl;
    std::cout<<"1.Modifier le titre"<<std::endl;
    std::cout<<"2.Modifier la description"<<std::endl;
    std::cout<<"3.Modifier le commentaire"<<std::endl;
    std::cout<<"4.Modifier la priorité"<<std::endl;
    std::cout<<"5.Modifier le pourcentage"<<std::endl;
    std::cout<<"6.Modifier la date de création"<<std::endl;
    std::cout<<"7.Modifier la date de cloture"<<std::endl;
    std::cout<<"8.Ajouter une sous-tache"<<std::endl;
    std::cout<<"9.Supprimer une sous tache"<<std::endl;
    int choix=0;
    std::cin>>choix;
    if(choix==0){select_task(n);}
    else if(choix==1){selected_task->change_title();
                    std::cout<<"Changement effectué"<<std::endl;
                    modify_task(n);}
    else if(choix==2){selected_task->change_description();
                    std::cout<<"Changement effectué"<<std::endl;
                    modify_task(n);}
    else if(choix==3){selected_task->change_comment();
                    std::cout<<"Changement effectué"<<std::endl;
                    modify_task(n);}
    else if(choix==4){selected_task->change_priority();
                    std::cout<<"Changement effectué"<<std::endl;
                    modify_task(n);}
    else if(choix==5){selected_task->change_percent();
                    std::cout<<"Changement effectué"<<std::endl;
                    modify_task(n);}
    else if(choix==6){selected_task->change_creation_date();
                    std::cout<<"Changement confirmé"<<std::endl;
                    modify_task(n);}
    else if(choix==7){selected_task->change_end_date();
                    std::cout<<"Changement confirmé"<<std::endl;
                    modify_task(n);}
    else if(choix==8){selected_task->add_subtask();
                    modify_task(n);}
    else if(choix==9){delete_sub_task(n);}
    else{std::cout<<"Cette touche n'est pas valide.Try again"<<std::endl;
                    modify_task(n);}
}

void task_body::remove_task(int n){
    vect_task.erase(vect_task.begin()+n);
    print_list_task();
}

void task_body::select_task(int n){
        task* selected_task=vect_task[n];
        std::cout<<"Gestion de la tâche sélectionnée"<<std::endl;
        std::cout<<"La tâche choisie est :"<<std::endl;
        selected_task->print();
        std::cout<<""<<std::endl;
        std::cout<<"Choisissez parmi les options suivantes"<<std::endl;
        std::cout<<"0.Retour"<<std::endl;
        std::cout<<"1.Modifier la tâche sélectionnée"<<std::endl;
        std::cout<<"2.Fermer la tâche"<<std::endl;
        std::cout<<"3.Activer la tâche"<<std::endl;
        std::cout<<"4.Supprimer la tache(irréversible)"<<std::endl;
        int number=0;
        std::cin>>number;
        if(number==0){print_list_task();}
        else if(number==1){modify_task(n);}
        else if(number==2){selected_task->close_task();
                        menu();}
        else if(number==3){selected_task->begin_task();
                        select_task(n);}
        else if(number==4){remove_task(n);}
        else{std::cout<<"Cette touche n'est pas valide.Try again"<<std::endl;
        select_task(n);}
        
}

void task_body::print_list_task(){
    std::cout<<"Liste des taches"<<std::endl;
    if (total==0){std::cout<<"Il n'y a aucune tache. Retour au menu de gestion des taches"<<std::endl;//cas où vect_task est vide
    menu();}
    else{int n=1;
    for(auto a:vect_task){
       std::cout<<n<<std::endl;
       a->print_title();
       n=n+1;
    }
    int nb=0;
    std::cout<<"Taper le numéro de la tache choisie (0=retour)"<<std::endl;
    std::cin>>nb;
    if(nb==0){menu();}
    else if(nb>0 && nb<=total){
        select_task(nb-1);
    }
    else{std::cout<<"Cette tache n'existe pas. Try again"<<std::endl;
    print_list_task();}
}
}

std::string task_body::ask_priority(){
    int n=0;
    std::cout<<"0=Priorité faible   1=Prioritaire 2=Priorité moyenne"<<std::endl;
    std::cin>>n;
    if(n==0){return "faible";}
    else if(n==1){return "prioritaire";}
    else if(n==2){return "moyen";}
    else{std::cout<<"Erreur. Try again"<<std::endl;
    ask_priority();
    return "";}
}

std::string task_body::ask_status(){
    int n=0;
    std::cout<<"0.Fermé  1.Ouvert "<<std::endl;
    std::cin>>n;
    if(n==0){return "fermé";}
    else if(n==1){return "ouvert";}
    else{std::cout<<"Erreur. Try again"<<std::endl;
    ask_status();
    return "";}
}

void task_body::save_tasks(){
    std::ofstream fichier("listsave.txt");
    if (fichier){
        fichier.seekp(0,std::ios::beg);//on commence au debut du fichier de sauvegarde
        for (auto a:vect_task){//on va, pour plus de facilité, sauvegarder toutes les taches en une seule fois
            int len=(a->vect_sub_task).size();//nombre de sous_tâches
            fichier<<len<<std::endl;
            fichier<<a->identifiant<<std::endl;
            fichier<<a->title<<std::endl;
            fichier<<a->description<<std::endl;
            fichier<<a->status<<std::endl;
            fichier<<a->percent<<std::endl;
            fichier<<a->priority<<std::endl;
            fichier<<a->comment<<std::endl;
            fichier<<a->creation_date<<std::endl;
            fichier<<a->end_date<<std::endl;
            fichier<<"sous taches associées"<<std::endl;
            for(auto subtask:a->vect_sub_task){//on parcoure toutes les sous-taches associée à la tache en cours d'écriture
                fichier<<subtask->identifiant<<std::endl;
                fichier<<subtask->title<<std::endl;
                fichier<<subtask->percent<<std::endl;
                fichier<<subtask->creation_date<<std::endl;
                fichier<<subtask->end_date<<std::endl;
            }
        }
    }
    else{std::cout<<"Pas de fichier de sauvegarde existant"<<std::endl;}
}

void task_body::add_new_task(){
    std::cout<<"Ajout de tache"<<std::endl;
    std::string titre="";
    std::string description="";
    std::string commentaire="";
    std::string statut="";
    std::string priorite="";
    std::string pourcentage;
    std::string date_debut;
    std::string date_fin;
    std::cout<<"Titre :";
    std::cin>>titre;
    std::cout<<""<<std::endl;
    std::cout<<"Description :";
    std::cin>>description;
    std::cout<<""<<std::endl;
    std::cout<<"Commentaire :";
    std::cin>>commentaire;
    std::cout<<""<<std::endl;
    statut=ask_status();
    priorite=ask_priority();
    std::cout<<"Pourcentage :";
    std::cin>>pourcentage;
    std::cout<<""<<std::endl;
    std::cout<<"Date de création (format jour/mois/année) :";
    std::cin>>date_debut;
    std::cout<<""<<std::endl;
    std::cout<<"Date de cloture (format jour/mois/année) :";
    std::cin>>date_fin;
    std::cout<<""<<std::endl;
    int id=0;//sera déterminé en lisant le fichier de sauvegarde
    task* new_task= new task(id,titre,description, date_debut,date_fin,statut,pourcentage,priorite,commentaire);
    new_task->print();
    std::cout<<"Ajouter cette tache à la liste de taches?"<<std::endl;
    std::cout<<"0.Non      1.Oui"<<std::endl;
    int choix=0;
    std::cin>>choix;
    if(choix==0){
        std::cout<<"Retour au menu principal"<<std::endl;
        menu();
        }
    else{
        vect_task.push_back(new_task);
        total++;
        std::cout<<"Tache ajoutée"<<std::endl;
        //save_tasks();
        menu();
        }
}

void task_body::delete_all(){
    while(vect_task.size()!=0){
        vect_task.erase(vect_task.begin());
    }
    std::cout<<"Liste de tâches vide"<<std::endl;
    menu();
}

void task_body::read_file(){
    std::ifstream fichier("listsave.txt");
    if(fichier){
        fichier.seekg(0,std::ios::beg);
        int num_ligne=0;
        int num_tache=0;
        int nbr_soustaches=0;
        std::string title;
        std::string description;
        std::string statut;
        std::string pourcentage;
        std::string priorite;
        std::string commentaire;
        std::string date_debut;
        std::string date_fin;
        std::string ligne;
        while(std::getline(fichier,ligne)){
            int id=num_tache;
            if(num_ligne==0){nbr_soustaches=std::atoi(ligne.c_str());num_ligne++;}
            else if(num_ligne==1){title=ligne;num_ligne++;}
            else if(num_ligne==2){description=ligne;num_ligne++;}
            else if(num_ligne==3){statut=ligne;num_ligne++;}
            else if(num_ligne==4){pourcentage=ligne;num_ligne++;}
            else if(num_ligne==5){priorite=ligne;num_ligne++;}
            else if(num_ligne==6){commentaire=ligne;num_ligne++;}
            else if(num_ligne==7){date_debut=ligne;num_ligne++;}
            else if(num_ligne=8){date_fin=ligne;num_ligne++;}
            else if(nbr_soustaches==0){
                task* new_task=new task(id,title,description,date_debut,date_fin,statut,pourcentage,priorite,commentaire);
                vect_task.push_back(new_task);
                total++;
                num_ligne=0;
                num_tache++;
                }
            else if(nbr_soustaches!=0){
                task* new_task=new task(id,title,description,date_debut,date_fin,statut,pourcentage,priorite,commentaire);
                num_ligne++;
                std::vector<task*> vect_newsubtask;
                for(int i=0;i<nbr_soustaches;i++){
                    std::string subtask_title;
                    std::string subtask_pourcentage;
                    std::string subtask_creation_date;
                    std::string subtask_end_date;
                        std::getline(fichier,ligne);
                        subtask_title=ligne;
                        std::getline(fichier,ligne);
                        subtask_pourcentage=ligne;
                        std::getline(fichier,ligne);
                        subtask_creation_date=ligne;
                        std::getline(fichier,ligne);
                        subtask_end_date=ligne;
                    
                    task* new_sub_task=new task(0,subtask_title,"",date_debut,date_fin,"",pourcentage,"","");
                    vect_newsubtask.push_back(new_sub_task);
                }
                new_task->vect_sub_task=vect_newsubtask;
                vect_task.push_back(new_task);
                total++;
                num_ligne=0;
                num_tache++;
            }

        }

    }
    else{
        std::cout<<"ERREUR: il n'y a pas de fichier de sauvegarde"<<std::endl;
    }
    menu();
}


void task_body::menu(){
    std::cout<<"Menu de gestion des tâches"<<std::endl;
    std::cout<<"0.Sauvegarder et quitter"<<std::endl;
    std::cout<<"1.Liste des taches"<<std::endl; 
    std::cout<<"2.Ajouter une tache"<<std::endl;
    std::cout<<"3.Effacer tout"<<std::endl;//Efface la liste de taches mais pas le fichier txt
    int choix=0;
    std::cin>>choix;
    if(choix==0){save_tasks();}
    else if(choix==1){print_list_task();}
    else if(choix==2){add_new_task();}
    else if(choix==3){delete_all();}
    else{std::cout<<"Cette touche n'existe pas. Try Again"<<std::endl;
    menu();}
}

int main(){
    task_body test;
    test.read_file();
}