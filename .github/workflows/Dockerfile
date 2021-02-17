FROM archlinux
RUN patched_glibc=glibc-linux4-2.33-4-x86_64.pkg.tar.zst && \
curl -LO "https://repo.archlinuxcn.org/x86_64/$patched_glibc" && \
bsdtar -C / -xvf "$patched_glibc"
RUN pacman -Sy --noconfirm avr-gcc avr-libc make
RUN pacman -U --noconfirm https://archive.archlinux.org/packages/b/binutils/binutils-2.35.1-1-x86_64.pkg.tar.zst

