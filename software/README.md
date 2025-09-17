# OPROGRAMOWANIE PRZYDATNE

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

- JAK SIE PORUSZAĆ?


1. i - mode edytowania kodu
2. Esc - mode zaznaczania i wpisyania komend
3. strzałki - poruszanie się po kodzie


Komendy: 
```
:w - zapisz plik
:q - wyjdż
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
-- Podstawowe opcje
vim.o.number = true
vim.o.relativenumber = true
vim.o.expandtab = true
vim.o.shiftwidth = 4
vim.o.tabstop = 4
vim.o.smartindent = true
vim.o.ignorecase = true
vim.o.smartcase = true
vim.o.termguicolors = true
vim.wo.cursorline = false
vim.cmd("syntax enable")

-- Packer bootstrap (jeśli nie masz)
local ensure_packer = function()
    local fn = vim.fn
    local install_path = fn.stdpath('data')..'/site/pack/packer/start/packer.nvim'
    if fn.empty(fn.glob(install_path)) > 0 then
        fn.system({'git', 'clone', '--depth', '1', 'https://github.com/wbthomason/packer.nvim', install_path})
        vim.cmd [[packadd packer.nvim]]
        return true
    end
    return false
end
local packer_bootstrap = ensure_packer()

require('packer').startup(function(use)
    use 'wbthomason/packer.nvim'

    -- Pliki
    use {
        "nvim-tree/nvim-tree.lua",
        requires = "nvim-tree/nvim-web-devicons",
        config = function()
            require("nvim-tree").setup({
                view = { width = 30, side = 'left' },
                filters = { dotfiles = false },
            })
        end
    }

    -- Terminal
    use {
        "voldikss/vim-floaterm",
        config = function()
            vim.g.floaterm_width = 0.9
            vim.g.floaterm_height = 0.6
            vim.g.floaterm_keymap_toggle = '<F12>'
        end
    }

    -- Treesitter (lepsze podświetlanie składni)
    use {
        'nvim-treesitter/nvim-treesitter',
        run = ':TSUpdate',
        config = function()
            require('nvim-treesitter.configs').setup {
                highlight = { enable = true },
                indent = { enable = true }
            }
        end
    }

    -- LSP (autouzupełnianie + diagnostyka)
    use {
        'neovim/nvim-lspconfig',
        config = function()
            local lspconfig = require('lspconfig')
            lspconfig.pyright.setup{}   -- Python
            lspconfig.tsserver.setup{}  -- JS/TS
            lspconfig.lua_ls.setup{}    -- Lua
        end
    }

    -- Autouzupełnianie jak w VS Code
    use {
        'hrsh7th/nvim-cmp',
        requires = {
            'hrsh7th/cmp-nvim-lsp',
            'hrsh7th/cmp-buffer',
            'hrsh7th/cmp-path',
            'L3MON4D3/LuaSnip'
        },
        config = function()
            local cmp = require'cmp'
            cmp.setup {
                snippet = {
                    expand = function(args)
                        require('luasnip').lsp_expand(args.body)
                    end,
                },
                mapping = cmp.mapping.preset.insert({
                    ['<Tab>'] = cmp.mapping.select_next_item(),
                    ['<S-Tab>'] = cmp.mapping.select_prev_item(),
                    ['<CR>'] = cmp.mapping.confirm({ select = true }),
                }),
                sources = cmp.config.sources({
                    { name = 'nvim_lsp' },
                    { name = 'buffer' },
                    { name = 'path' }
                })
            }
        end
    }

    -- Statusline
    use {
        'nvim-lualine/lualine.nvim',
        requires = { 'nvim-tree/nvim-web-devicons' },
        config = function()
            require('lualine').setup {
                options = { theme = 'gruvbox' }
            }
        end
    }

    -- Kolorystyka (VSCode feel)
    use { 'Mofiqul/vscode.nvim',
        config = function()
            vim.cmd("colorscheme vscode")
        end
    }

    if packer_bootstrap then
        require('packer').sync()
    end
end)

-- Skróty klawiszowe
vim.api.nvim_set_keymap('n', '<F2>', ':NvimTreeToggle<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<F12>', ':FloatermToggle<CR>', { noremap = true, silent = true })
```
