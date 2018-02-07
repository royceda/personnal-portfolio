var myApp = angular.module('myApp', ['ngAnimate', 'ngRoute', 'ui.bootstrap']);


angular.module('myApp').config([ '$routeProvider', function($routeProvider){
  $routeProvider
  .when('/', {
    templateUrl: 'home/index.html',
    controller: 'indexCtrl'})
    .when('/RO', {
      templateUrl: 'home/operation_research.html',
      controller: 'indexCtrl'})
      .when('/gallery', {
        templateUrl: 'gallery/index.html',
        controller: 'imgCtrl'})
        .otherwise({redirectTo : '/'});
      }]);


      angular.module('myApp').controller('imgCtrl', function ($scope, $uibModal){
        $scope.getImagePath = function(imageName) {
          return "images/temp/" + imageName;
        };


        $scope.myImages = ["van_cleef.jpg","sacree_coeur.jpg","4427.JPG","bdx2.jpg", "bdx3.jpg", "bdx4.jpg", "bdx5.jpg", "bir_hakeim.jpg",
        "cap.jpg", "chaban.jpg", "christmas.jpg", "defense.jpg", "eiffel.jpg", "hausman.jpg", "paris.jpg", "paris2.jpg",
        "place_bourse.jpg","travel.jpg","westBeach.jpg","tls.jpg", "moon.jpg", "plan4.jpg","IMG_3645.JPG","IMG_3551.JPG","IMG_3548.JPG",
        "IMG_3517.JPG","IMG_3516.JPG","IMG_3414.JPG","IMG_3296.JPG"];

      });





      angular.module('myApp').controller('indexCtrl', function ($scope, $uibModal){

        $scope.items = ['item1', 'item2', 'item3'];

        $scope.open = function (name) {
          var modalInstance = $uibModal.open({
            animation: true,
            ariaLabelledBy: 'modal-title',
            ariaDescribedBy: 'modal-body',
            templateUrl: 'modal/'+name+'.html',
            controller: 'ModalInstanceCtrl',
            controllerAs: '$ctrl',
            size: "lg",
            resolve: {
              items: function () {
                return $scope.items;
              }
            }
          });
        };
      });



      angular.module('myApp').controller('ModalInstanceCtrl', function ($uibModalInstance,$scope, items) {

        $scope.items = items;
        $scope.selected = {
          item: $scope.items[0]
        };

        $scope.ok = function () {
          $uibModalInstance.close($ctrl.selected.item);
        };

        $scope.back = function () {
          $uibModalInstance.dismiss('cancel');
        };
      });
