# Fraud_detect - Détecteur Hybride de Phishing (C++ / Python)

pare-feu applicatif conçu pour détecter les tentatives de phishing , lien non sur .... 

Ce projet est une démonstration d'architecture système **hybride**, combinant la performance brute du **C++** (gestion mémoire manuelle et rapidité ) et la flexibilité de **Python** (orchestration et logique sémantique).

---

## Objectif du Projet

Les solutions de sécurité actuelles posent souvent un dilemme : être rapides mais limitées , ou intelligentes mais lentes (analyse IA).

**fraud_detect propose une approche en entonnoir :**
1.  **Performance :** Un moteur C++ filtre instantanément les menaces connues (Blacklist deja etablie ) avec une latence quasi-nulle.
2.  **Intelligence :** Un cerveau Python analyse ensuite la sémantique des messages restants pour détecter la manipulation psychologique (Simulation IA). PARTIE 2 A VENIR 

---

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
