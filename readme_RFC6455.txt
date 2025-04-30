🔑 1. Objectif du protocole WebSocket

    Fournir un canal full-duplex (bidirectionnel) entre un client (souvent un navigateur) et un serveur.

    Réduction de la surcharge HTTP pour des échanges rapides et fréquents (par ex. chat, jeux en ligne, données temps réel).

🧱 2. **La phase de "Handshake"

    C’est une négociation initiale faite via HTTP/1.1.

    Le client envoie une requête GET avec l’en-tête Upgrade: websocket pour indiquer qu’il veut basculer en WebSocket.

    Le serveur répond avec un code 101 Switching Protocols s’il accepte.

    Étapes à bien comprendre :

        En-têtes HTTP spécifiques (ex. Sec-WebSocket-Key, Sec-WebSocket-Version)

        Validation du handshake côté serveur (incluant le SHA-1 et base64)

🔄 3. Encodage du flux de données (Framing)

    Les données WebSocket sont envoyées en frames (cadres) avec une structure spécifique.

    Types de frames :

        Texte (opcode 0x1)

        Binaire (opcode 0x2)

        Contrôle : fermeture (0x8), ping (0x9), pong (0xA)

    Structure d’une frame :

        FIN bit, RSV1–3, opcode

        Masquage (MASK bit), payload length, masque (pour client)

        Données utiles

    ⚠️ Important : le client doit toujours masquer les données, pas le serveur.

📏 4. Gestion des longueurs de messages

    Payloads peuvent être :

        ≤ 125 octets (inclus dans l’en-tête)

        126 : suivi de 2 octets pour longueur

        127 : suivi de 8 octets

    Utile pour gérer les messages volumineux (ex. fichiers binaires).

🛑 5. Fermeture de la connexion

    Utilisation de la frame de fermeture (opcode 0x8).

    Peut inclure un code de statut (par ex. 1000 pour fermeture normale) et un message.

    Important pour gérer proprement les déconnexions, erreurs, timeouts.

🔐 6. Sécurité et contraintes

    Le RFC mentionne plusieurs aspects :

        DoS : attention aux connexions massives

        Injection de données : bien valider les entrées

        Respect du même principe d’origine (Same-Origin Policy)

    Le protocole ne chiffre pas les données (sauf si utilisé avec wss://, qui utilise TLS).

🔄 7. Échanges Ping/Pong

    Pour garder une connexion "vivante".

    Le client ou serveur peut envoyer un ping.

    L’autre côté doit répondre avec un pong (automatique dans beaucoup d’implémentations).

    Peut aussi être utilisé pour tester la latence.

📚 8. Extensions et sous-protocoles

    Le protocole supporte :

        Les sous-protocoles (Sec-WebSocket-Protocol) pour définir un format applicatif (ex: JSON-RPC, MQTT, etc.).

        Les extensions (Sec-WebSocket-Extensions), comme la compression (permessage-deflate).
