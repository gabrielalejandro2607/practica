// Mostrar/ocultar galería global debajo de todos los productos
function toggleGaleriaGlobal(boton, galeriaId) {
  const galeria = document.getElementById(galeriaId);
  const visible = galeria.style.display === "block";

  galeria.style.display = visible ? "none" : "block";
  boton.textContent = visible ? "Ver más" : "Ver menos";
}

// Simulación de atención al cliente
function mostrarMensaje() {
  alert("¡Hola!, Gracias por contactarnos. Un asesor se pondra en contacto contigo en breve.");
}
function añadirAlCarrito(nombreProducto) {
  const lista = document.getElementById("lista-carrito");

  const item = document.createElement("li");
  item.textContent = nombreProducto;

  const botonEliminar = document.createElement("button");
  botonEliminar.textContent = "X";
  botonEliminar.className = "btn-eliminar";
  botonEliminar.onclick = function () {
    lista.removeChild(item);
  };

  item.appendChild(botonEliminar);
  lista.appendChild(item);
}