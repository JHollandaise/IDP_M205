syntax enable " enable syntax processing
set tabstop=4 " tab by four spaces
set softtabstop=4 " num spaces in tab when editing
set expandtab " tabs == spaces
set number
set showcmd
set cursorline
filetype indent on " load filetype-specific indent files
set wildmenu " autocomplete
set lazyredraw " don't always redraw the screen
set showmatch " matching brackets with a highlight 
set incsearch " search as each char entered
set hlsearch "highlight matches

set foldenable " enable text folding (loops shortened etc)
set foldlevelstart=10 " open most folds by default
set foldnestmax=10 " max of 10 nested folds
nnoremap <space> za
set foldmethod=indent " fold based on indent level

" move by visual lines not actual lines
nnoremap j gj
nnoremap k gk
inoremap jk <esc>
