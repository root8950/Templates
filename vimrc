" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim

"execute pathogen#infect()
set autoindent
set nocompatible
set noswapfile
syntax on

" The following to have Vim jump to the last position when
" reopening a file
if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif

" The following to have Vim load indentation rules and plugins
" according to the detected filetype.
if has("autocmd")
  filetype plugin indent on
endif

" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif


"extras
set showmode                    " always show what mode we're currently editing in
set backspace=indent,eol,start  " allow backspacing over everything in insert mode
set autoindent                  " always set autoindenting on
set copyindent                  " copy the previous indentation on autoindenting
set number                      " always show line numbers
set autowrite  			"Save on buffer switch
set wrap 			"Wrap lines

source $VIMRUNTIME/mswin.vim
behave mswin

"autocmd vimenter * NERDTree
"map <C-n> :NERDTreeToggle<CR>

map <F2> :tabnew <CR>
map <F8> :w <CR> :!g++ -Wall % <CR>
map <F9> :w <CR> :!g++ -std=c++0x -Wall % <CR>
map <F10> :w <CR> :!g++ -g -Wall % <CR>
map <F12> :!gdb ./a.out <CR>