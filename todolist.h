#include <iostream>
#include <string>
#include <vector>
#include <exception>
#ifndef TODOLIST_H
#define TODOLIST_H

class OrderError:public std::runtime_error{
    public:
    OrderError(const char* msg) noexcept: std::runtime_error(msg){}
};

class task{
    friend class task_body;
    protected:
    int identifiant;
    std::string title;
    std::string description;
    std::string creation_date;//sera définie par l'utilisateur
    std::string end_date;//sera définie par l'utilisateur
    std::string status;//ouverte ou fermée
    std::string percent;//il s'est révélé plus facile en terme de lecture/écriture dans le fichier d'en faire une chaîne de caractères
    std::string priority;//faible,prioritaire ou indifférent
    std::string comment;
    std::vector<task*> vect_sub_task;

    public:
    task(int id, std::string titre, std::string d, std::string date_debut, std::string date_fin, std::string statut, std::string pourcent,std::string prio, std::string commentaire):
        identifiant(id), title(titre), description(d), creation_date(date_debut), end_date(date_fin), status(statut), percent(pourcent), priority(prio), comment(commentaire){}
    
    void change_title();
    void change_description();
    void change_priority();
    void change_comment();
    void add_sub_task();
    void change_percent();
    void change_creation_date();
    void change_end_date();
    void close_task();
    void begin_task();
    void print();
    void print_title();
    void print_sub_task(task* sub_task);//à la différence de print, on ne fera apparaître que certains éléments car plus simple
    void add_subtask();
};

class task_body{
    protected:
    int total;//nombre de tâches au total
    std::vector<task*> vect_task;
    public:
    task_body(): total(0){};
    void read_file();
    void save_tasks();
    void menu();
    void print_list_task();
    void add_new_task();
    std::string ask_priority();//On l'utilise dans add_new_task afin de limiter facilement les choix possibles
    std::string ask_status();//On l'utilise dans add_new_task afin de limiter facilement les choix possibles
    void select_task(int n);
    void delete_all();//supprime toutes les tâches de task_body
    void modify_task(int n);
    void delete_sub_task(int n);
    void remove_task(int n);
  

};

#endif //TODOLIST_H