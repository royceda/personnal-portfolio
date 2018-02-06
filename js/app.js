var myApp = angular.module('myApp', ['ngAnimate', 'ngRoute', 'ui.bootstrap']);


myApp.config([ '$routeProvider', function($routeProvider){
  $routeProvider
  .when('/', {
    templateUrl: 'home/index.html',
    controller: 'indexCtrl'})
    .when('/gallery', {
      templateUrl: 'gallery/index.html',
      controller: 'indexCtrl'})
      .otherwise({redirectTo : '/'});
    }]);



    myApp.controller('indexCtrl', function ($scope, $uibModal){

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



    myApp.controller('ModalInstanceCtrl', function ($uibModalInstance,$scope, items) {

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
