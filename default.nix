{ pkgs ? import <nixpkgs> {} }:

with pkgs; stdenv.mkDerivation {
  name = "learn_discrete_math";
  nativeBuildInputs = [
    cmake
    conan
    ninja
  ];
}
