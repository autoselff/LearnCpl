# OPROGRAMOWANIE PRZYDATNE

## VS CODIUM  HELP

gruvbox = best theme

## NVIM HELP

- Instalacja

Windows
```bash
winget install Neovim.Neovim
```

Linux
```bash
sudo apt update
sudo apt install neovim
nvim --version
```
```bash
sudo pacman -S neovim
nvim --version

```

- Otworz config neovim

```bash
nvim ~/.config/nvim/init.lua
```

- Synchronizuj załączone paczki

```nvim
:PackerSync
```

- Jak zainstalować packera?

```bash
git clone --depth 1 https://github.com/wbthomason/packer.nvim \
~/.local/share/nvim/site/pack/packer/start/packer.nvim
```

- Przykład configu
``` lua
vim.cmd [[packadd packer.nvim]]

vim.wo.number = true
vim.o.expandtab = true
vim.o.shiftwidth = 4
vim.o.tabstop = 4
vim.wo.cursorline = true
vim.o.ignorecase = true
vim.o.smartcase = true
vim.cmd("syntax on")

require('packer').startup(function()
    use 'wbthomason/packer.nvim'

    use {
        "voldikss/vim-floaterm",
        config = function()
            vim.g.floaterm_width = 0.9
            vim.g.floaterm_height = 0.6
            vim.g.floaterm_keymap_toggle = '<F12>'
        end
    }

    use {
        "nvim-tree/nvim-tree.lua",
        requires = "nvim-tree/nvim-web-devicons",
        config = function()
            require("nvim-tree").setup({
                view = {
                    width = 30,
                    side = 'left',
                },
                filters = {
                    dotfiles = false,
                },
            })
        end
    }
end)

vim.api.nvim_set_keymap('n', '<F12>', ':FloatermToggle<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<F2>', ':NvimTreeToggle<CR>', { noremap = true, silent = true })
```