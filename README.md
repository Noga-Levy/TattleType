<h1 align="center">TattleType</h1>
<p align="center">
	<img src="https://img.shields.io/badge/language-555555?style=flat-square"><img src="https://img.shields.io/badge/C%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white?style=flat-square">
	<img src="https://img.shields.io/badge/license-MIT-green?style=flat-square">
	<img src="https://img.shields.io/badge/platform-Windows-lightgrey?style=flat-square">
</p>
<h3 align="center">What can keyloggers <em>actually</em> find? And what are you letting your computer see?</h3>

By imitating real keyloggers, TattleType--an educational, non-malicious keylogger--answers just that. 

Rather than inspiring paranoia, TattleType employs a playful twist to keep the experience light-hearted--whenever it detects sensitive information (e.g, gmail addresses), it notifies the user with a Windows pop-up describing a new achievement. For example, when "@gmail.com" is detected, it sends

<p align="center">
	<img src="https://github.com/Noga-Levy/TattleType/blob/main/Assets/example_notification.png">
</p>

Via these pop-ups, users become more aware of what information they share with their device without suffering the stress caused by most cyber-awareness applications.

## User Interaction

Once running, the program listens to all of the user's key presses. When specific "triggers" are detected, a Windows pop-up will appear--all the user has to do at that point is read it and press "OK" to continue.

## Installation
### Download `.exe` file
Head over to the [Releases page](https://github.com/Noga-Levy/TattleType/releases/) and download the `.exe` file from the most recent release.  Run the `.exe` file to start the program.

### Build from source
Alternatively, clone the repository and compile `functions.h`, `send_notification.cpp`, `keylogger.cpp`, and `main.cpp`--all from the `Scripts` folder--into one executable:

```
git clone https://github.com/Noga-Levy/TattleType

cd TattleType/Scripts
g++ functions.h main.cpp send_notification.cpp keylogger.cpp -o TattleType
```

## Project Structure
Given the project size, there are only two main folders:
- `Assets/` ~ Contains all assets relevant to the program/repository.
- `Scripts/` ~ Contains all the scripts relevant to the program.

## License
TattleType is licensed under the MIT License--see the [LICENSE](https://github.com/Noga-Levy/TattleType/blob/master/LICENSE) file for details.
