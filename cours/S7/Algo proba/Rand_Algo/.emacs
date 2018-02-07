(setq load-path (cons "/net/ens/renault/.emacs.d/" load-path))
(load "python-mode")

(global-set-key (kbd "C-c C-e") 'py-execute-region)
