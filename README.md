# Fraud_detect - Détecteur Hybride de Phishing (C++ / Python)

pare-feu applicatif conçu pour détecter les tentatives de phishing , lien non sur .... 

Ce projet est une démonstration d'architecture système **hybride**, combinant la performance brute du **C++** (gestion mémoire manuelle et rapidité ) et la flexibilité de **Python** (orchestration et logique sémantique).

---

## Objectif du Projet

Les solutions de sécurité actuelles posent souvent un dilemme : être rapides mais limitées , ou intelligentes mais lentes (analyse IA).

**fraud_detect propose une approche en entonnoir :**
1.  **Performance :** Un moteur C++ filtre instantanément les menaces connues (Blacklist deja etablie ) avec une latence quasi-nulle.
2.  **Intelligence :** Un cerveau Python analyse ensuite la sémantique des messages restants pour détecter la manipulation psychologique (Simulation IA avec un LLM local ). AMELIORATION FUTURE 

---
## Comment Lancer le Projet
Ce projet nécessite g++ (Compilateur C++) et Python 3.

1. Compilation du Moteur C++
Bash

cd cpp_core
g++ main.cpp url.cpp -o sentinel
2. Exécution du Programme
Bash

cd ../python_brain
python3 brain.py
## Architecture Technique

Le projet repose sur une communication inter-processus (**IPC**) stricte, appliquant les concepts de programmation système Unix.

```mermaid
sequenceDiagram
   

    User->>Python: Entrée: "evil.com"
    Python->>PipeIn: Write: "evil.com\n"
    PipeIn->>CPP: Read URL
    Note over CPP: Vérification RAM (O(N))
    CPP->>PipeOut: Write: "DANGER\n"
    PipeOut->>Python: Read Result
    Python->>User: Alerte Rouge 🚨
Fraud_detect/
├── cpp_core/           # Le Moteur Performance
│   ├── main.cpp        # Interface I/O et boucle d'événements
│   ├── url.cpp         # Logique de gestion mémoire (new/delete)
│   └── url.h           # Définition de la classe
├── python_brain/       # Le Cerveau Orchestrateur
│   ├── brain.py        # Point d'entrée utilisateur
│   └── sentinel_wrapper.py # Gestionnaire de processus (subprocess)
└── data/
    └── blacklist.txt   # Base de données simulée  


##Comment Lancer le Projet
