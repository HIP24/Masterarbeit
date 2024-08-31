\begin{comment}
	Ja, du denkst richtig! Wenn du die Latenz des Systems messen möchtest, die es benötigt, um das Signal bei der PWM anzukommen, und die 20 ms Signalperiode des Servomotors ignorieren möchtest, dann konzentrierst du dich auf die reine Reaktionszeit des Systems.
	
	In diesem Fall misst du die Zeit von der Befehlsausgabe bis zum Eintreffen des Signals bei der PWM. Die 20 ms, die der Servomotor benötigt, um das Signal zu verarbeiten und die Bewegung zu starten, werden in deiner Latenzdefinition nicht berücksichtigt.
	
	Das bedeutet, dass du die Latenz als die Zeit definierst, die das System benötigt, um das Signal an die PWM zu senden, ohne die zusätzliche Verzögerung durch die Signalperiode des Servomotors einzubeziehen.
	
	In diesem Versuch wird die Latenz des Systems gemessen, die benötigt wird, um das Signal von der Befehlsausgabe bis zum Eintreffen bei der PWM (Pulsweitenmodulation) zu erfassen. Die Signalperiode des Servomotors von 20 ms wird dabei ignoriert, da sie für die Definition der Systemlatenz nicht relevant ist. Die Latenz wird somit als die reine Reaktionszeit des Systems definiert, ohne die zusätzliche Verzögerung durch die Signalperiode des Servomotors zu berücksichtigen.
	\end{comment}