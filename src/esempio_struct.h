class Frazione {
  friend void debug(const Frazione &f);

public:
  Frazione(int n, int d = 1);
  Frazione();
  ~Frazione();

  void scrivi() const;

  int numeratore() const;
  void numeratore(int valore);

  int denominatore() const { return den; };
  void denominatore(int valore) { den = valore; }

  static int numero_istanze() { return istanze; }

  // Operatore di conversione a double
  operator double() { return (double)num / den; }

  Frazione &operator+=(const Frazione &f);
  Frazione &operator-=(const Frazione &f);

protected: // oppure private:
  int num, den;
  static int istanze;
};
