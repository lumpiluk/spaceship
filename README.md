# Spaceship

## Creating TOJ files from logs

While the game does create logs, it will not generate TOJ files of the following format by itself:
```
SOA values
number of repetitions
number of "probe first" decisions
```

For this task we wrote a Python script located in the ExperimentUtil directory. To generate TOJ files for all experiment logs located in Saved/Logs, simply run the following lines in a terminal:
```
cd ExperimentUtil
python make_toj.py -d ../Saved/Logs
```


## Using GIT -- Command line instructions

### SSH-Key einrichten

Prüfe, ob ein Key vorhanden ist:
```
#cat ~/.ssh/id_rsa.pub
```

Wenn nicht vorhanden, folgende Schritte ausführen:
```
#ssh-keygen -t rsa -C "<Deine EmailAdresse>"
```

folgenden Dialog mit Enter bestätigen, NICHTS EINGEBEN!!:
```
#Enter file in which to save the key (/c/Users/<Username>/.ssh/id_rsa):
```
	
Anschließend bei Wunsch eine Passphrase angeben und bestätigen.
Wenn alles geklappt hat, kannst du dir deinen öffentlichen Schlüssel anzeigen lassen:
```
#cat ~/.ssh/id_rsa.pub
```

### ----Hier hinspringen, wenn schon ein Schlüssel vorhanden ist

Kopiere den öffentl. Schlüssel mithilfe von:
```
#clip < ~/.ssh/id_rsa.pub
```

Gehe nun auf: https://git.cs.upb.de/profile/keys/new 
Füge den Key ein und klicke auf "Add Key". 
SSH ist nun eingerichtet.

### Git global setup (Nur einmal notwendig)

(```<xxx>``` anpassen)
```
git config --global user.name "<Name>"
git config --global user.email "<Email-Adresse>"
```


### Existing folder or Git repository

Clone git repo:
```
#git clone irb-git@git.cs.upb.de:......git
```

Setze den Masterzweig als Standard (optional):
```
#git branch --set-upstream-to=origin/master master
```

hole aktuellen Stand aus dem Repo:
```
#git pull
```