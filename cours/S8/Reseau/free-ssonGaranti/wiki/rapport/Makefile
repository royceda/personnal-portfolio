all:	rapport

rapport:
	pdflatex rapport.tex

view: rapport
	evince rapport.pdf &

.PHONY:	clean

clean:
	rm *.aux *.pdf *.log
