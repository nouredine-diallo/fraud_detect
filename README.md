#  Fraud_detect - Détecteur Hybride de Phishing (C++ / Python)

**Fraud_detect** est un pare-feu applicatif conçu pour détecter les tentatives de phishing et les URLs malveillantes en temps réel.

Ce projet est une démonstration d'architecture système **hybride**, combinant la performance brute du **C++** (gestion mémoire manuelle et rapidité) et la flexibilité de **Python** (orchestration et logique sémantique).

---

##  Objectif du Projet

Les solutions de sécurité actuelles posent souvent un dilemme : être rapides mais limitées (listes noires), ou intelligentes mais lentes (analyse IA).

**Fraud_detect propose une approche en "entonnoir" :**

1.  ** Performance :** Un moteur C++ filtre instantanément les menaces connues (Blacklist déjà établie) avec une latence quasi-nulle.
2.  ** Intelligence :**  Amelioration futures : Un cerveau Python analyse ensuite la sémantique des messages restants pour détecter la manipulation psychologique (Simulation actuelle / Intégration LLM local prévue).

---

##  Architecture Technique

Le projet repose sur une communication inter-processus (**IPC**) stricte, appliquant les concepts de programmation système Unix (Pipes, stdin/stdout).

```mermaid
sequenceDiagram
    participant User as Utilisateur
    participant Python as Orchestrateur (Brain)
    participant PipeIn as STDIN (Tube Entrée)
    participant CPP as Moteur C++ (Sentinel)
    participant PipeOut as STDOUT (Tube Sortie)

    User->>Python: Entrée: "evil.com"
    Python->>PipeIn: Write: "evil.com\n"
    PipeIn->>CPP: Read URL
    Note over CPP: Vérification RAM (O(N))
    CPP->>PipeOut: Write: "DANGER\n"
    PipeOut->>Python: Read Result
    Python->>User: Alerte Rouge 
