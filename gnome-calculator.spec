Name:           gnome-calculator
Version:        3.22.3
Release:        1%{?dist}
Summary:        A desktop calculator

License:        GPLv3+
URL:            https://wiki.gnome.org/Apps/Calculator
Source0:        https://download.gnome.org/sources/%{name}/3.22/%{name}-%{version}.tar.xz

BuildRequires:  desktop-file-utils
BuildRequires:  gettext
BuildRequires:  intltool
BuildRequires:  itstool
BuildRequires:  libsoup-devel
BuildRequires:  mpfr-devel
BuildRequires:  pkgconfig(glib-2.0)
BuildRequires:  pkgconfig(gtk+-3.0)
BuildRequires:  pkgconfig(gtksourceview-3.0)
BuildRequires:  pkgconfig(libxml-2.0)
BuildRequires:  /usr/bin/appstream-util

Provides:  gcalctool = 6.6.2-3
Obsoletes: gcalctool < 6.6.2-3


%description
gnome-calculator is a powerful graphical calculator with financial,
logical and scientific modes. It uses a multiple precision package
to do its arithmetic to give a high degree of accuracy.


%prep
%setup -q


%build
%configure --disable-static
make %{?_smp_mflags}


%install
%make_install
find %{buildroot} -name '*.la' -delete
%find_lang %{name} --with-gnome --all-name


%check
appstream-util validate-relax --nonet %{buildroot}/%{_datadir}/appdata/gnome-calculator.appdata.xml
desktop-file-validate %{buildroot}/%{_datadir}/applications/gnome-calculator.desktop


%postun
if [ $1 -eq 0 ] ; then
     glib-compile-schemas %{_datadir}/glib-2.0/schemas &> /dev/null || :
fi


%posttrans
glib-compile-schemas %{_datadir}/glib-2.0/schemas &> /dev/null || :


%files -f %{name}.lang
%doc NEWS
%license COPYING
%{_bindir}/gcalccmd
%{_bindir}/gnome-calculator
%{_libdir}/gnome-calculator/
%{_libexecdir}/gnome-calculator-search-provider
%{_datadir}/appdata/gnome-calculator.appdata.xml
%{_datadir}/applications/gnome-calculator.desktop
%{_datadir}/dbus-1/services/org.gnome.Calculator.SearchProvider.service
%{_datadir}/glib-2.0/schemas/org.gnome.calculator.gschema.xml
%{_datadir}/gnome-shell/
%{_mandir}/man1/gnome-calculator.1*
%{_mandir}/man1/gcalccmd.1*


%changelog
* Wed Feb 22 2017 Matthias Clasen <mclasen@redhat.com> - 3.22.3-1
- Rebase to 3.22.3
  Resolves: rhbz#1386880

* Wed May  6 2015 Alexander Larsson <alexl@redhat.com> - 3.14.1-2
- Add new translations

* Mon Mar 23 2015 Richard Hughes <rhughes@redhat.com> - 3.14.1-1
- Update to 3.14.1
- Resolves: #1174575

* Fri Jan 24 2014 Daniel Mach <dmach@redhat.com> - 3.8.2-4
- Mass rebuild 2014-01-24

* Wed Jan 22 2014 Alexander Larsson <alexl@redhat.com> - 3.8.2-3
- Add missing translations
  Resolves: rhbz#1030337

* Fri Dec 27 2013 Daniel Mach <dmach@redhat.com> - 3.8.2-2
- Mass rebuild 2013-12-27

* Mon May 13 2013 Matthias Clasen <mclasen@redhat.com> - 3.8.2-1
- Update to 3.8.2

* Mon Apr 15 2013 Richard Hughes <rhughes@redhat.com> - 3.8.1-1
- Update to 3.8.1

* Tue Mar 26 2013 Kalev Lember <kalevlember@gmail.com> - 3.8.0-1
- Update to 3.8.0

* Wed Mar 20 2013 Kalev Lember <kalevlember@gmail.com> - 3.7.92-1
- Update to 3.7.92

* Thu Mar  7 2013 Matthias Clasen <mclasen@redhat.com> - 3.7.91-1
- Update to 3.7.91

* Fri Feb 22 2013 Adel Gadllah <adel.gadllah@gmail.com> - 3.7.90-2
- Bump obsolete (mass rebuild bumped the gcalcool nevr)

* Thu Feb 21 2013 Kalev Lember <kalevlember@gmail.com> - 3.7.90-1
- Update to 3.7.90

* Wed Feb 06 2013 Kalev Lember <kalevlember@gmail.com> - 3.7.5-1
- Update to 3.7.5

* Wed Jan 16 2013 Matthias Clasen <mclasen@redhat.com> - 3.7.4-2
- Fix keyword translations in desktop file

* Wed Jan 16 2013 Matthias Clasen <mclasen@redhat.com> - 3.7.4-1
- Renamed package from gcalctool to gnome-calculator
