Name:           gnome-calculator
Version:        3.8.2
Release:        4%{?dist}
Summary:        A desktop calculator

Group:          Applications/System
License:        GPLv2+
URL:            http://live.gnome.org/Gcalctool
#VCS: git:git://git.gnome.org/gcalctool
Source0:        http://download.gnome.org/sources/%{name}/3.8/%{name}-%{version}.tar.xz

Patch0:         gnome-calculator-translations.patch

BuildRequires: glib2-devel
BuildRequires: gtk3-devel
BuildRequires: libsoup-devel
BuildRequires: desktop-file-utils
BuildRequires: gettext
BuildRequires: flex
BuildRequires: bison
BuildRequires: intltool
BuildRequires: itstool

Requires(post): glib2
Requires(postun): glib2

Provides:  gcalctool = 6.6.2-3
Obsoletes: gcalctool < 6.6.2-3


%description
gnome-calculator is a powerful graphical calculator with financial,
logical and scientific modes. It uses a multiple precision package
to do its arithmetic to give a high degree of accuracy.


%prep
%setup -q

%patch0 -p2 -b .translations


%build
%configure
make %{?_smp_mflags}


%install
make install DESTDIR=$RPM_BUILD_ROOT

desktop-file-validate $RPM_BUILD_ROOT%{_datadir}/applications/gcalctool.desktop

%find_lang %{name} --with-gnome --all-name


%postun
if [ $1 -eq 0 ] ; then
     glib-compile-schemas %{_datadir}/glib-2.0/schemas &> /dev/null || :
fi


%posttrans
glib-compile-schemas %{_datadir}/glib-2.0/schemas &> /dev/null || :


%files -f %{name}.lang
%doc COPYING NEWS
%{_bindir}/gcalccmd
%{_bindir}/gnome-calculator
%{_datadir}/applications/gcalctool.desktop
%{_datadir}/glib-2.0/schemas/org.gnome.calculator.gschema.xml
%{_datadir}/gnome-calculator
%doc %{_mandir}/man1/gnome-calculator.1.gz
%doc %{_mandir}/man1/gcalccmd.1.gz


%changelog
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
